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

auto GetCube()
{
    float vertices[] = {
    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,

    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,

     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,

    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    };
    return vertices;
}

void run() {

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        Logger::PrintInfo("Failed to initialize glad");
        return;
    }
    glViewport(0, 0, (int)Screen::get_size().x, (int)Screen::get_size().y);
    //设置窗口回调
    //glfwSetFramebufferSizeCallback(window, frameBuffer_Changed);

    float plane[] = {
        -4.0f, -0.5f, -4.0f,     1.0f, 1.0f, 1.0f, 1.0f,		0.0f, 0.0f,    0.0f, 1.0f, 0.0f,
        -4.0f, -0.5f, 4.0f,      1.0f, 1.0f, 1.0f, 1.0f,		1.0f, 0.0f,    0.0f, 1.0f, 0.0f,
        4.0f , -0.5f, 4.0f,       1.0f, 1.0f, 1.0f, 1.0f,		1.0f, 1.0f,    0.0f, 1.0f, 0.0f,
        4.0f , -0.5f, 4.0f,       1.0f, 1.0f, 1.0f, 1.0f,		1.0f, 1.0f,    0.0f, 1.0f, 0.0f,
        4.0f,  -0.5f, -4.0f,      1.0f, 1.0f, 1.0f, 1.0f,		0.0f, 1.0f,    0.0f, 1.0f, 0.0f,
        -4.0f, -0.5f, -4.0f,     1.0f, 1.0f, 1.0f, 1.0f,		0.0f, 0.0f,    0.0f, 1.0f, 0.0f,
    };
    float cube_vertices[] = {
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,

        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,

         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,

        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
    };
    float vertices[] = {
        -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, -1.0f,    0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,    0.0f, 0.0f, -1.0f,    1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,    0.0f, 0.0f, -1.0f,     1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,    0.0f, 0.0f, -1.0f,     1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,    0.0f, 0.0f, -1.0f,     0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, -1.0f,     0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 1.0f,     0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 1.0f,     1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 1.0f,     1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 1.0f,     1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 1.0f,     0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 1.0f,     0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,    -1.0f, 0.0f, 0.0f,     1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,    -1.0f, 0.0f, 0.0f,     1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,    -1.0f, 0.0f, 0.0f,    0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,    -1.0f, 0.0f, 0.0f,    0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,    -1.0f, 0.0f, 0.0f,    0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,    -1.0f, 0.0f, 0.0f,    1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 0.0f,    1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,    1.0f, 0.0f, 0.0f,    1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 0.0f,    0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 0.0f,    0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,    1.0f, 0.0f, 0.0f,    0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 0.0f,    1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,	0.0f, -1.0f, 0.0f,    0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,	0.0f, -1.0f, 0.0f,    1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,	0.0f, -1.0f, 0.0f,    1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,	0.0f, -1.0f, 0.0f,    1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,	0.0f, -1.0f, 0.0f,    0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,	0.0f, -1.0f, 0.0f,    0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 0.0f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 0.0f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 0.0f,  0.0f, 1.0f,
    };

    //VAO
    VertexArrayObject VAO;
    VertexBufferObject VBO;

    VAO.Use(
        [&VBO, &vertices]() {
            VBO.Bind();
            //传送顶点数据至VBO
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

            //顶点属性指针
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
            glEnableVertexAttribArray(2);
        });

    Resource::SetReadPath("F:/SapphireEngine/_data");
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
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    ShaderProgram cmProg{ "cmProg" };
    Shader cmVert = Shader::CreateVetexShader("CubeMapVert", FileUtil::ReadAllText(shaderPath + "/CubeMap.vert"));
    Shader cmFrag = Shader::CreateFragmentShader("CubeMapFrag", FileUtil::ReadAllText(shaderPath + "/CubeMap.frag"));
    cmProg.AttachShader(cmVert);
    cmProg.AttachShader(cmFrag);
    cmProg.Link();

    CubeMap* cubeMap = Resource::Load<CubeMap>("texture/skybox");

    Node* cameraNode = Scene::Current()->AddNode(new Node("camera"));
    Camera* cam = cameraNode->AddComponent<Camera>(); {
        cam->size = Screen::get_size();
        cam->fov = 45.f;
        cam->far = 10000.f;
        cam->get_transform()->set_position({ 0, 0, 200 });
        cam->backgroundColor = Color::Gray();
        cam->SetMain();
    }
    scene->AddNode(new Node("FreeCameraCtrl"))->AddComponent<FreeCamera>();

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

        youtong->GetChildAt(0)->GetComponent<MeshRenderer>()->OnDraw(&shaderProg);

        gridProg.UseProgram();

        scene->OnUpdate();
        SystemInterface::PollEvents();
        Input::PollEvents();

    }
    delete scene;
}




int main()
{
    EngineDefaultLauncher launcher;
    launcher.Initialize();

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