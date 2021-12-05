#pragma once
#include <ThirdParty/glad/glad.h>
#include <ThirdParty/glfw/include/GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <CoreLib/File.h>


#include <SapphireEngine/Private/BaseInterface.h>
#include <functional>
#include <array>
#include <format>
#include <CoreLib/CommonException.h>
#include <SapphireEngine/_include.h>
#include <SapphireEngine/Components/MeshRenderer.h>
#include <SapphireEngine/Components/Camera.h>
#include <SapphireEngine/Components/FreeCamera.h>
#include <SapphireEngine/Assets/CubeMap.h>
#include <CoreLib/DebugTool.hpp>

using namespace std;
using namespace SapphireEngine;
using namespace SapphireEngine::Private;
using namespace SapphireEngine::InputDevice;


struct VertexArrayObject
{
    uint32_t id;
    VertexArrayObject()
    {
        glGenVertexArrays(1, &id);
    }
    void Use(const std::function<void()>& func)
    {
        Bind();
        func();
        Unbind();
    }
    void Bind()
    {
        glBindVertexArray(id);
    }
    void Unbind()
    {
        glBindVertexArray(0);
    }
    ~VertexArrayObject()
    {
        glDeleteVertexArrays(1, &id);
    }
};
struct VertexBufferObject
{
    uint32_t id;
    VertexBufferObject()
    {
        glGenBuffers(1, &id);
    }
    void Use(const std::function<void()>& func)
    {
        Bind();
        func();
        Unbind();
    }
    void Bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, id);
    }
    void Unbind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
    ~VertexBufferObject()
    {
        glDeleteBuffers(1, &id);
    }
};

struct ElementBufferObject
{
    uint32_t id;
    ElementBufferObject()
    {
        glGenBuffers(1, &id);
    }
    void Use(const std::function<void()>& func)
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
        func();
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
    ~ElementBufferObject()
    {
        glDeleteBuffers(1, &id);
    }
};

void run() {

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        Logger::PrintInfo("Failed to initialize glad");
        return;
    }
    glViewport(0, 0, (int)Screen::get_size().x, (int)Screen::get_size().y);
    //设置窗口回调
    //glfwSetFramebufferSizeCallback(window, frameBuffer_Changed);
    //Shader::CreateFragmentShader("PBR", FileUtil::ReadAllText(Resource::GetReadPath() + "/shader/PBR.frag"));


    auto cube_vertices = Mesh::CreateCube();
    auto vertices = Mesh::CreateStdLayoutCube();

    //VAO
    VertexArrayObject VAO;
    VertexBufferObject VBO;

    VAO.Use(
        [&VBO, &vertices]() {
            VBO.Bind();
            //传送顶点数据至VBO
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);

            //顶点属性指针
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
            glEnableVertexAttribArray(2);
        });


    string dataPath = "F:/SapphireEngine/_data";
    string texturePath = dataPath + "/texture";
    string shaderPath = dataPath + "/shader";

    //Light
    VertexArrayObject lightVAO;
    lightVAO.Use(
        [&VBO]() {
            VBO.Bind();
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
            glEnableVertexAttribArray(2);
        });

#pragma region 着色器

    Shader vertexShader = Shader::CreateVetexShader("StandardVertexShader", FileUtil::ReadAllText(shaderPath + "/Standard.vert"));
    Shader fragmentShader = Shader::CreateFragmentShader("StandardFragmentShader", FileUtil::ReadAllText(shaderPath + "/Standard.frag"));
    Shader gridvertShader = Shader::CreateVetexShader("GridVert", FileUtil::ReadAllText(shaderPath + "/Grid.vert"));
    Shader gridfragShader = Shader::CreateFragmentShader("GridFrag", FileUtil::ReadAllText(shaderPath + "/Grid.frag"));

    ShaderProgram lightShaderProg{ "LightShader" };
    Shader lightShader = Shader::CreateFragmentShader("LightShader", FileUtil::ReadAllText(shaderPath + "/Light.frag"));
    lightShaderProg.AttachShader(vertexShader);
    lightShaderProg.AttachShader(lightShader);
    lightShaderProg.Link();


    std::vector<Vector3> vertices1;
    std::vector<Vector4> indices1;
    int slices = 10;
    for (int j = 0; j <= slices; ++j) {
        for (int i = 0; i <= slices; ++i) {
            float x = (float)i / (float)slices;
            float y = 0;
            float z = (float)j / (float)slices;
            vertices1.push_back(Vector3(x, y, z));
        }
    }

    for (int j = 0; j < slices; ++j) {
        for (int i = 0; i < slices; ++i) {

            int row1 = j * (slices + 1);
            int row2 = (j + 1) * (slices + 1);

            indices1.push_back(Vector4(row1 + i, row1 + i + 1, row1 + i + 1, row2 + i + 1));
            indices1.push_back(Vector4(row2 + i + 1, row2 + i, row2 + i, row1 + i));

        }
    }

    ShaderProgram gridProg{ "gridProg" };
    gridProg.AttachShader(gridvertShader);
    gridProg.AttachShader(gridfragShader);
    gridProg.Link();

    Texture2D* texture2d = Resource::Load<Texture2D>("texture/p.jpg");
    Texture2D* spec2d = Resource::Load<Texture2D>("texture/specular.jpg");

    Scene* scene = (new Scene())->SetCurrentState();

    Node* youtong = scene->AddNode(Resource::Load<Model>("model/youtong.fbx")->Instantiate());


    //创建着色器程序
    ShaderProgram shaderProg{ "Standard" };
    shaderProg.AttachShader(vertexShader);
    shaderProg.AttachShader(fragmentShader);
    shaderProg.Link();
    //shaderProg.AddTexture(texture2d);
    //shaderProg.AddTexture(spec2d);
    shaderProg.UseProgram();

    vertexShader.DeleteShader();
    fragmentShader.DeleteShader();
    lightShader.DeleteShader();
#pragma endregion

    //VertexArrayObject cubeMapVAO;
    //VertexBufferObject cubeMapVBO;
    //cubeMapVAO.Use(
    //    [&]() {
    //        cubeMapVBO.Bind();
    //        glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);
    //        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    //        glEnableVertexAttribArray(0);
    //    });

    uint32_t cubeMapVAO;
    glGenVertexArrays(1, &cubeMapVAO);
    uint32_t cubeMapVBO;
    glGenBuffers(1, &cubeMapVBO);
    glBindVertexArray(cubeMapVAO);
    glBindBuffer(GL_ARRAY_BUFFER, cubeMapVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    ShaderProgram cmProg{ "cmProg" };
    Shader cmVert = Shader::CreateVetexShader("CubeMapVert", FileUtil::ReadAllText(shaderPath + "/CubeMap.vert"));
    Shader cmFrag = Shader::CreateFragmentShader("CubeMapFrag", FileUtil::ReadAllText(shaderPath + "/CubeMap.frag"));
    cmProg.AttachShader(cmVert);
    cmProg.AttachShader(cmFrag);
    cmProg.Link();

    ShaderProgram pbrProg{ "pbr" };
    Shader pbrVert = Shader::CreateVetexShader("pbrVert", FileUtil::ReadAllText(shaderPath + "/PBR.vert"));
    Shader pbrFrag = Shader::CreateFragmentShader("pbrFrag", FileUtil::ReadAllText(shaderPath + "/PBR.frag"));
    pbrProg.AttachShader(pbrVert);
    pbrProg.AttachShader(pbrFrag);
    pbrProg.Link();

    CubeMap* cubeMap = Resource::Load<CubeMap>("texture/skybox");

    Node* cameraNode = Scene::Current()->AddNode(new Node("camera"));
    Camera* cam = cameraNode->AddComponent<Camera>(); {
        cam->size = Screen::get_size();
        cam->fov = 45.f;
        cam->far = 10000.f;
        cam->get_transform()->set_position({ 0, 0, 200 });
        cam->backgroundColor = Color::Black();
        cam->SetMain();
    }
    scene->AddNode(new Node("FreeCameraCtrl"))->AddComponent<FreeCamera>();

    auto t_albedo = Resource::Load<Texture2D>("model/rustediron2_basecolor.png");
    auto t_normal = Resource::Load<Texture2D>("model/rustediron2_normal.png");
    auto t_metallic = Resource::Load<Texture2D>("model/rustediron2_metallic.png");
    auto t_roughness = Resource::Load<Texture2D>("model/rustediron2_roughness.png");
    auto t_ao = Resource::Load<Texture2D>("model/rustediron2_ao.jpg");

    auto m1_albedo = Resource::Load<Texture2D>("model/mat1/sphere_lambert1_BaseColor.png");
    auto m1_normal = Resource::Load<Texture2D>("model/mat1/sphere_lambert1_Normal.png");
    auto m1_metallic = Resource::Load<Texture2D>("model/mat1/sphere_lambert1_Metallic.png");
    auto m1_roughness = Resource::Load<Texture2D>("model/mat1/sphere_lambert1_Roughness.png");
    auto m1_ao = Resource::Load<Texture2D>("model/rustediron2_ao.jpg");

    auto m2_albedo = Resource::Load<Texture2D>("model/mat2/sphere_lambert1_BaseColor.png");
    auto m2_normal = Resource::Load<Texture2D>("model/mat2/sphere_lambert1_Normal.png");
    auto m2_metallic = Resource::Load<Texture2D>("model/mat2/sphere_lambert1_Metallic.png");
    auto m2_roughness = Resource::Load<Texture2D>("model/mat2/sphere_lambert1_Roughness.png");
    auto m2_ao = Resource::Load<Texture2D>("model/rustediron2_ao.jpg");

    Mesh* sphere = Mesh::CreateSphere(64, 64);

    Node* sphereNode = scene->AddNode(Resource::Load<Model>("model/sphere.fbx")->Instantiate());
    Node* sphereNode2 = scene->AddNode(Resource::Load<Model>("model/sphere.fbx")->Instantiate());
    Node* sphereNode3 = scene->AddNode(Resource::Load<Model>("model/sphere.fbx")->Instantiate());

    while (!Application::IsQuit())
    {
        auto projMat = cam->GetProjectionMat();
        auto viewMat = cam->GetViewMat();

        RenderInterface::EnableDepthTest();
        RenderInterface::Clear(Camera::Main()->backgroundColor);

        {   //cubemap
            RenderInterface::DisableDepthTest();
            glDepthMask(GL_FALSE);
            cmProg.UseProgram();
            cmProg.SetUniformMatrix4fv("projection", projMat);
            cmProg.SetUniformMatrix4fv("view", (Matrix)(Matrix3)viewMat);
            cmProg.SetUniformInt("skybox", 0);
            glBindVertexArray(cubeMapVAO);
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_CUBE_MAP, cubeMap->id);
            glDrawArrays(GL_TRIANGLES, 0, 36);
            glDepthMask(GL_TRUE);

            RenderInterface::EnableDepthTest();
        }

        Matrix model = Matrix::Translate(Matrix::One(), Vector3::Zero());

        Matrix lightModel = Matrix::One();
        lightModel = Matrix::Translate(lightModel, Vector3(100.5f, 150.0f, 0.0f));
        lightShaderProg.UseProgram();
        lightShaderProg.SetUniformMatrix4fv("projection", projMat.get_value_ptr());
        lightShaderProg.SetUniformMatrix4fv("view", viewMat.get_value_ptr());
        lightShaderProg.SetUniformMatrix4fv("model", lightModel);

        lightVAO.Use([]() { glDrawArrays(GL_TRIANGLES, 0, 36); });

        pbrProg.UseProgram();
        pbrProg.SetUniformMatrix4fv("projection", projMat);
        pbrProg.SetUniformMatrix4fv("view", viewMat);
        //pbrProg.SetUniformMatrix4fv("model", Matrix::Scale(Vector3{20,20,20}));
        pbrProg.SetUniformMatrix4fv("model", model);
        pbrProg.SetUniformVector3("camPos", cam->get_transform()->get_position());

        [&]() {
            pbrProg.SetUniformInt("albedoMap", 1);
            pbrProg.SetUniformInt("normalMap", 2);
            pbrProg.SetUniformInt("metallicMap", 3);
            pbrProg.SetUniformInt("roughnessMap", 4);
            pbrProg.SetUniformInt("aoMap", 5);

            Vector3 lights_pos[] = { {1.5,1.5,0}, {0,-1,9}, {-1,0.5,1} };
            Vector3 lights_color[] = { {1,1,1}, {0.7,0.7,0.7},{0.5,0.5,0.5} };
            for (size_t i = 0; i < sizeof(lights_pos) / sizeof(Vector3); i++)
            {
                pbrProg.SetUniformVector3("lightPositions[" + to_string(i) + "]", lights_pos[i]);
                pbrProg.SetUniformVector3("lightColors[" + to_string(i) + "]", lights_color[i]);
            }


            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, m1_albedo->get_id());

            glActiveTexture(GL_TEXTURE2);
            glBindTexture(GL_TEXTURE_2D, m1_normal->get_id());

            glActiveTexture(GL_TEXTURE3);
            glBindTexture(GL_TEXTURE_2D, m1_metallic->get_id());

            glActiveTexture(GL_TEXTURE4);
            glBindTexture(GL_TEXTURE_2D, m1_roughness->get_id());

            glActiveTexture(GL_TEXTURE5);
            glBindTexture(GL_TEXTURE_2D, m1_ao->get_id());

            glActiveTexture(GL_TEXTURE0);


            auto mesh_render = sphereNode->GetChildAt(0)->GetComponent<MeshRenderer>();
            auto vao = mesh_render->get_mesh()->VAO;
            glBindVertexArray(vao);
            glDrawElements(GL_TRIANGLES, mesh_render->get_mesh()->indices.size(), GL_UNSIGNED_INT, 0);
            glBindVertexArray(0);


            pbrProg.SetUniformMatrix4fv("model", Matrix::Translate(Matrix::One(), {2.3,0,}));
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, t_albedo->get_id());

            glActiveTexture(GL_TEXTURE2);
            glBindTexture(GL_TEXTURE_2D, t_normal->get_id());

            glActiveTexture(GL_TEXTURE3);
            glBindTexture(GL_TEXTURE_2D, t_metallic->get_id());

            glActiveTexture(GL_TEXTURE4);
            glBindTexture(GL_TEXTURE_2D, t_roughness->get_id());

            glActiveTexture(GL_TEXTURE5);
            glBindTexture(GL_TEXTURE_2D, t_ao->get_id());

            glActiveTexture(GL_TEXTURE0);

            auto mesh_render2 = sphereNode2->GetChildAt(0)->GetComponent<MeshRenderer>();
            auto vao2 = mesh_render->get_mesh()->VAO;
            glBindVertexArray(vao);
            glDrawElements(GL_TRIANGLES, mesh_render2->get_mesh()->indices.size(), GL_UNSIGNED_INT, 0);
            glBindVertexArray(0);

            //pbrProg.SetUniformMatrix4fv("model", Matrix::Translate(Matrix::One(), { -2.3,0,0 }));
            //glActiveTexture(GL_TEXTURE1);
            //glBindTexture(GL_TEXTURE_2D, m2_albedo->get_id());

            //glActiveTexture(GL_TEXTURE2);
            //glBindTexture(GL_TEXTURE_2D, m2_normal->get_id());

            //glActiveTexture(GL_TEXTURE3);
            //glBindTexture(GL_TEXTURE_2D, m2_metallic->get_id());

            //glActiveTexture(GL_TEXTURE4);
            //glBindTexture(GL_TEXTURE_2D, m2_roughness->get_id());

            //glActiveTexture(GL_TEXTURE5);
            //glBindTexture(GL_TEXTURE_2D, m2_ao->get_id());

            //glActiveTexture(GL_TEXTURE0);

            //auto mesh_render3 = sphereNode3->GetChildAt(0)->GetComponent<MeshRenderer>();
            //auto vao3 = mesh_render->get_mesh()->VAO;
            //glBindVertexArray(vao);
            //glDrawElements(GL_TRIANGLES, mesh_render3->get_mesh()->indices.size(), GL_UNSIGNED_INT, 0);
            //glBindVertexArray(0);

            //glBindVertexArray(sphere->VAO);
            //glDrawElements(GL_TRIANGLES, sphere->indices.size(), GL_UNSIGNED_INT, 0);
            //glBindVertexArray(0);
        }();

        [&]() {
            shaderProg.UseProgram();
            shaderProg.SetUniformMatrix4fv("projection", projMat);
            shaderProg.SetUniformMatrix4fv("view", viewMat);
            shaderProg.SetUniformMatrix4fv("model", model);

            shaderProg.SetUniformColor("lightColor", Color::Yellow());
            shaderProg.SetUniformVector3("lightPos", (Vector3)Matrix::Translate(lightModel, Vector3::One()).GetColumn(3));
            shaderProg.SetUniformVector3("viewPos", cam->get_transform()->get_position());

            shaderProg.SetUniformVector3("mat_ambient", { 1.f, 1.f, 1.f });
            shaderProg.SetUniformFloat("mat_shininess", 16.0f);

            shaderProg.SetUniformVector3("light.ambient", { 0.2f, 0.2f, 0.2f });
            shaderProg.SetUniformVector3("light.diffuse", { 0.5f, 0.5f, 0.5f });
            shaderProg.SetUniformVector3("light.specular", { 1.f, 1.f, 1.f });
        };



        //youtong->GetChildAt(0)->GetComponent<MeshRenderer>()->OnDraw(&pbrProg);

        gridProg.UseProgram();

        scene->OnUpdate();
        SystemInterface::PollEvents();
        Input::PollEvents();

    }
    delete scene;
}


template<typename _Ty, int _N>
struct Struct
{
    _Ty Values[_N];
};

int main()
{
    EngineDefaultLauncher launcher;
    launcher.Initialize();

    Resource::SetReadPath("F:/SapphireEngine/_data");




    try
    {
        run();
    }
    catch (std::exception& e)
    {
        cout << e.what() << endl;
    }

    launcher.Terminate();

    return 0;
}