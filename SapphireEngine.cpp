#pragma once
#include "SapphireEngine.h"


using namespace std;
using namespace SapphireEngine;
using namespace SapphireEngine::Private;
using namespace SapphireEngine::InputDevice;

#define ENGINE_EDITOR 1

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
    //设置窗口回调
    //glfwSetFramebufferSizeCallback(window, frameBuffer_Changed);

    auto pbr = Resource::LoadLocal<PBRPipeline::PBRTexture>("model/rustediron2.pbrtex");

    auto cube_vertices = Utility::MeshBuilder::CreateCube();
    auto vertices = Utility::MeshBuilder::CreateStdLayoutCube();

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


    string dataPath = Resource::GetLocalPath();
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

    Texture2D* texture2d = Resource::LoadLocal<Texture2D>("texture/p.jpg");
    Texture2D* spec2d = Resource::LoadLocal<Texture2D>("texture/specular.jpg");

    Scene* scene = (new Scene())->SetCurrentState();

    //Node* youtong = scene->AddNode(Resource::LoadLocal<Model>("model/youtong.fbx")->Instantiate());


    //创建着色器程序
    ShaderProgram shaderProg{ "Standard" };
    shaderProg.AttachShader(vertexShader);
    shaderProg.AttachShader(fragmentShader);
    shaderProg.Link();
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

    CubeMap* cubeMap = Resource::LoadLocal<CubeMap>("texture/skybox/skycube.asset");


    Node* cameraNode = Scene::Current()->AddNode(new Node("camera"));
    Camera* cam = cameraNode->AddComponent<Camera>(); {
        cam->size = Screen::get_size();
        cam->fov = 45.f;
        cam->far = 10000.f;
        cam->get_transform()->set_position({ 0, 0, 5 });
        cam->backgroundColor = Color::Black();
        cam->SetMain();
    }
    scene->AddNode(new Node("FreeCameraCtrl"))->AddComponent<FreeCamera>();

    auto rustediron2 = Resource::LoadLocal<PBRPipeline::PBRTexture>("model/rustediron2.pbrtex");

    //auto m1_albedo = Resource::LoadLocal<Texture2D>("model/mat1/sphere_lambert1_BaseColor.png");
    //auto m1_normal = Resource::LoadLocal<Texture2D>("model/mat1/sphere_lambert1_Normal.png");
    //auto m1_metallic = Resource::LoadLocal<Texture2D>("model/mat1/sphere_lambert1_Metallic.png");
    //auto m1_roughness = Resource::LoadLocal<Texture2D>("model/mat1/sphere_lambert1_Roughness.png");
    //auto m1_ao = Resource::LoadLocal<Texture2D>("model/rustediron2_ao.jpg");

    //auto m2_albedo = Resource::LoadLocal<Texture2D>("model/mat2/sphere_lambert1_BaseColor.png");
    //auto m2_normal = Resource::LoadLocal<Texture2D>("model/mat2/sphere_lambert1_Normal.png");
    //auto m2_metallic = Resource::LoadLocal<Texture2D>("model/mat2/sphere_lambert1_Metallic.png");
    //auto m2_roughness = Resource::LoadLocal<Texture2D>("model/mat2/sphere_lambert1_Roughness.png");
    //auto m2_ao = Resource::LoadLocal<Texture2D>("model/rustediron2_ao.jpg");


    Node* sphereNode = scene->AddNode(Resource::LoadLocal<Model>("model/sphere.fbx")->Instantiate());
    Material* sphere_mat1 = new Material;
    sphere_mat1->textures.insert({ "AlbedoMap", rustediron2->get_albedo() });
    sphere_mat1->textures.insert({ "NormalMap",rustediron2->get_normal() });
    sphere_mat1->textures.insert({ "MetallicMap", rustediron2->get_metallic() });
    sphere_mat1->textures.insert({ "RoughnessMap",rustediron2->get_roughness() });
    sphere_mat1->textures.insert({ "AoMap",rustediron2->get_ao() });
    sphere_mat1->program = &pbrProg;
    sphere_mat1->Bind();
    sphereNode->GetChildAt(0)->GetComponent<MeshRenderer>()->set_material(sphere_mat1);

    //Node* sphereNode2 = scene->AddNode(Resource::LoadLocal<Model>("model/sphere.fbx")->Instantiate());
    //Node* sphereNode3 = scene->AddNode(Resource::LoadLocal<Model>("model/sphere.fbx")->Instantiate());

    auto rp = RenderPipelines::ScriptablePipeline();

    while (!Application::IsQuit())
    {

#if ENGINE_EDITOR
        
#endif

        auto projMat = cam->GetProjectionMat();
        auto viewMat = cam->GetViewMat();

        RenderInterface::EnableDepthTest();
        RenderInterface::Clear(Camera::Main()->backgroundColor);

        {   //cubemap
            RenderInterface::DisableDepthTest();
            glDepthMask(GL_FALSE);
            cmProg.UseProgram();

            rp.SetMVP(&cmProg, projMat, (Matrix)(Matrix3)viewMat, Matrix::One() );

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
        rp.SetMVP(&lightShaderProg, projMat, viewMat, lightModel);

        lightVAO.Use([]() { glDrawArrays(GL_TRIANGLES, 0, 36); });

        pbrProg.UseProgram();
        rp.SetMVP(&pbrProg, projMat, viewMat, model);
        pbrProg.SetUniformVector3("camPos", cam->get_transform()->get_position());

        [&]() {

            Vector3 lights_pos[] = { {1.5,1.5,0}, {0,-1,9}, {-1,0.5,1} };
            Vector3 lights_color[] = { {1,1,1}, {0.7,0.7,0.7},{0.5,0.5,0.5} };
            for (size_t i = 0; i < sizeof(lights_pos) / sizeof(Vector3); i++)
            {
                pbrProg.SetUniformVector3("lightPositions[" + to_string(i) + "]", lights_pos[i]);
                pbrProg.SetUniformVector3("lightColors[" + to_string(i) + "]", lights_color[i]);
            }


            sphereNode->GetChildAt(0)->GetComponent<MeshRenderer>()->Render();



        }();

        //gridProg.UseProgram();

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

    Resource::SetLocalPath("D:/Codes/SapphireEngine/_data");

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