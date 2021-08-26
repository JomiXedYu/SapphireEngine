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
#include <SapphireEngine/Assets/CubeMap.h>

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
        glBindVertexArray(id);
        func();
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

    Resource::SetReadPath("E:/SapphireEngine/_data");
    string dataPath = "E:/SapphireEngine/_data";
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

    //glBindVertexArray(0);


    //uint32_t planeVAO;
    //glGenVertexArrays(1, &planeVAO);
    //glBindVertexArray(planeVAO);

    //uint32_t VBO_PLANE;
    //glGenBuffers(1, &VBO_PLANE);
    //glBindBuffer(GL_ARRAY_BUFFER, VBO_PLANE);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(plane), plane, GL_STATIC_DRAW);


    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)0);
    //glEnableVertexAttribArray(0);
    //glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(3 * sizeof(float)));
    //glEnableVertexAttribArray(1);
    //glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(7 * sizeof(float)));
    //glEnableVertexAttribArray(2);
    //glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(9 * sizeof(float)));
    //glEnableVertexAttribArray(3);

    //glBindVertexArray(0);

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

    Node* youtong = Resource::Load<Node>("model/youtong.fbx");

    Scene* scene = new Scene();
    scene->AddNode(youtong);

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

    //RenderCamera camera;
    //camera.size = Screen::get_size();
    //camera.fov = 45.0f;
    //camera.near = 0.1f;
    //camera.far = 1000.0f;
    //camera.position = Vector3(0, 0, 3);
    //camera.rotationEuler = Vector3::Zero();
    //camera.backgroundColor = Color(42, 42, 42);

    Vector3 modelPos;


    VertexArrayObject cubeMapVAO;

    CubeMap* cubeMap = Resource::Load<CubeMap>("texture/skybox");

    Node* cameraNode = new Node("camera");
    Camera* cam = cameraNode->AddComponent<Camera>();
    Camera::SetMain(cam);

    cam->size = Screen::get_size();
    cam->fov = 45.f;
    cam->far = 1000.f;
    cam->get_transform()->set_position(Vector3(0, 0, 3));
    cam->backgroundColor = Color(42, 42, 42);

    while (!Application::IsQuit())
    {
        float timedelta = Time::DeltaTime();

        RenderInterface::EnableDepthTest();
        RenderInterface::Clear(Camera::Main()->backgroundColor);

        float hori = Input::GetAxis("horizontal");
        float vert = Input::GetAxis("vertical");

        cam->get_transform()->Translate(cam->Forward() * vert * 5);
        cam->get_transform()->Translate(cam->Right() * hori * 5);

        if (Input::GetKey(KeyCode::E))
        {
            cam->get_transform()->Translate(Vector3::Up() * timedelta * 500);
        }
        else if (Input::GetKey(KeyCode::Q))
        {
            cam->get_transform()->Translate(-Vector3::Up() * timedelta * 500);
        }

        if (Input::GetKey(KeyCode::LeftAlt))
        {
            if (Input::GetMouseButton(1))
            {
                cam->get_transform()->Translate(cam->Forward() * Input::GetAxis("mouseX") * timedelta * 10);
            }
            if (Input::GetMouseButton(2))
            {
                cam->get_transform()->Translate(cam->Right() * -Input::GetAxis("mouseX") * timedelta * 10);
                cam->get_transform()->Translate(Vector3::Up() * Input::GetAxis("mouseY") * timedelta * 10);
            }
        }
        else
        {
            if (Input::GetMouseButton(1))
            {
                cam->get_transform()->Rotate({ 0, Input::GetAxis("mouseX") * timedelta * 10, 0 });
                cam->get_transform()->Rotate({ -Input::GetAxis("mouseY") * timedelta * 10 ,0 ,0 });
            }
        }

        Matrix model = Matrix::Translate(Matrix::One(), modelPos);

        auto projMat = cam->GetProjectionMat();
        auto viewMat = cam->GetViewMat();


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
        //cube->GetChildAt(0)->GetComponent<MeshRenderer>()->OnDraw(&shaderProg);

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