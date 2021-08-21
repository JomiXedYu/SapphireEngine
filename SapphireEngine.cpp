﻿#pragma once
#include <ThirdParty/glad/glad.h>
#include <ThirdParty/glfw/include/GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <CoreLib/File.h>


#include <SapphireEngine/Private/BaseInterface.h>


#include <format>
#include <CoreLib/CommonException.h>
#include <SapphireEngine/_include.h>
#include <SapphireEngine/Components/MeshRenderer.h>

using namespace std;
using namespace SapphireEngine;
using namespace SapphireEngine::Private;
using namespace SapphireEngine::InputDevice;


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
        -0.5f, -0.5f, -0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		0.0f, 0.0f,    0.0f, 0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		1.0f, 0.0f,    0.0f, 0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		1.0f, 1.0f,    0.0f, 0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		1.0f, 1.0f,    0.0f, 0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		0.0f, 1.0f,    0.0f, 0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		0.0f, 0.0f,    0.0f, 0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		0.0f, 0.0f,    0.0f, 0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		1.0f, 0.0f,    0.0f, 0.0f, 1.0f,
         0.5f,  0.5f,  0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		1.0f, 1.0f,    0.0f, 0.0f, 1.0f,
         0.5f,  0.5f,  0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		1.0f, 1.0f,    0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		0.0f, 1.0f,    0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		0.0f, 0.0f,    0.0f, 0.0f, 1.0f,

        -0.5f,  0.5f,  0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		1.0f, 0.0f,    -1.0f, 0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		1.0f, 1.0f,    -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		0.0f, 1.0f,    -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		0.0f, 1.0f,    -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		0.0f, 0.0f,    -1.0f, 0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		1.0f, 0.0f,    -1.0f, 0.0f, 0.0f,

         0.5f,  0.5f,  0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		1.0f, 0.0f,    1.0f, 0.0f, 0.0f,
         0.5f,  0.5f, -0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		1.0f, 1.0f,    1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		0.0f, 1.0f,    1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		0.0f, 1.0f,    1.0f, 0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		0.0f, 0.0f,    1.0f, 0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		1.0f, 0.0f,    1.0f, 0.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		0.0f, 1.0f,    0.0f, -1.0f, 0.0f,
         0.5f, -0.5f, -0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		1.0f, 1.0f,    0.0f, -1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		1.0f, 0.0f,    0.0f, -1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		1.0f, 0.0f,    0.0f, -1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		0.0f, 0.0f,    0.0f, -1.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		0.0f, 1.0f,    0.0f, -1.0f, 0.0f,

        -0.5f,  0.5f, -0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		0.0f, 1.0f,    0.0f, 1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		1.0f, 1.0f,    0.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		1.0f, 0.0f,    0.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		1.0f, 0.0f,    0.0f, 1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		0.0f, 0.0f,    0.0f, 1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,	1.0f, 1.0f, 1.0f, 1.0f,		0.0f, 1.0f,    0.0f, 1.0f, 0.0f,
    };

    uint32_t indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    //VAO
    uint32_t VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    //创建VBO对象
    uint32_t VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //传送顶点数据至VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


    //EBO
    //uint32_t EBO;
    //glGenBuffers(1, &EBO);
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //顶点属性指针
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(7 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(9 * sizeof(float)));
    glEnableVertexAttribArray(3);
    //unbind
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    string dataPath = "E:/SapphireEngine/_data";
    string texturePath = dataPath + "/texture";
    string shaderPath = dataPath + "/shader";

    //Bitmap* bp = Resource::LoadBitmap(texturePath + "/p.jpg");



    //Light
    uint32_t lightVAO;
    glGenVertexArrays(1, &lightVAO);
    glBindVertexArray(lightVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(7 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(9 * sizeof(float)));
    glEnableVertexAttribArray(3);

    glBindVertexArray(0);


    uint32_t planeVAO;
    glGenVertexArrays(1, &planeVAO);
    glBindVertexArray(planeVAO);

    uint32_t VBO_PLANE;
    glGenBuffers(1, &VBO_PLANE);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_PLANE);
    glBufferData(GL_ARRAY_BUFFER, sizeof(plane), plane, GL_STATIC_DRAW);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(7 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(9 * sizeof(float)));
    glEnableVertexAttribArray(3);

    glBindVertexArray(0);

#pragma region 着色器

    Shader vertexShader = Shader::CreateVetexShader("StandardVertexShader", FileUtil::ReadAllText(shaderPath + "/Standard.vert"));
    Shader fragmentShader = Shader::CreateFragmentShader("StandardFragmentShader", FileUtil::ReadAllText(shaderPath + "/Standard.frag"));

    ShaderProgram lightShaderProg;
    Shader lightShader = Shader::CreateFragmentShader("LightShader", FileUtil::ReadAllText(shaderPath + "/Light.frag"));
    lightShaderProg.AttachShader(vertexShader);
    lightShaderProg.AttachShader(lightShader);
    lightShaderProg.Link();


    Texture2D* texture2d = Resource::Load<Texture2D>(texturePath + "/p.jpg");
    Texture2D* spec2d = Resource::Load<Texture2D>(texturePath + "/specular.jpg");

    Node* youtong = Resource::Load<Node>(dataPath + "/model/youtong.fbx");
    
    Scene* scene = new Scene();
    scene->AddNode(youtong);
    
    //创建着色器程序
    ShaderProgram shaderProg;
    shaderProg.AttachShader(vertexShader);
    shaderProg.AttachShader(fragmentShader);
    shaderProg.Link();
    shaderProg.AddTexture(texture2d);
    shaderProg.AddTexture(spec2d);
    shaderProg.UseProgram();

    vertexShader.DeleteShader();
    fragmentShader.DeleteShader();
    lightShader.DeleteShader();
#pragma endregion

    RenderCamera camera;
    camera.size = Screen::get_size();
    camera.fov = 45.0f;
    camera.near = 0.1f;
    camera.far = 100.0f;
    camera.position = Vector3(0, 0, 3);
    camera.rotationEuler = Vector3::Zero();
    //camera.backgroundColor = Color::Blue();

    Vector3 modelPos;

    //渲染循环
    while (!Application::IsQuit())
    {
        float timedelta = Time::DeltaTime();

        glEnable(GL_DEPTH_TEST);
        //glDepthFunc(GL_LEQUAL);

        //glClearColor(0, 0, 0, 1);
        Color bgColor = camera.backgroundColor;
        glClearColor(bgColor.r(), bgColor.g(), bgColor.a(), bgColor.a());

        //glClearDepth(1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //cout << Input::getAxis("horizontal") << "    " << Input::getAxis("vertical") << endl;
        shaderProg.UseProgram();
        //glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);

        //4x4变换矩阵 变成变换矩阵，用变换矩阵乘向量
        Matrix trans = Matrix::One();

        float hori = Input::GetAxis("horizontal");
        float vert = Input::GetAxis("vertical");

        camera.position += camera.Forward() * vert * 0.1f;
        camera.position += camera.Right() * hori * 0.1f;

        if (Input::GetKey(KeyCode::Space))
        {
            camera.position += Vector3::Up() * timedelta * 10;
        }
        else if (Input::GetKey(KeyCode::LeftControl))
        {
            camera.position -= Vector3::Up() * timedelta * 10;
        }
        if (Input::GetMouseButton(1))
        {
            camera.rotationEuler.y += Input::GetAxis("mouseX") * timedelta * 10;
            camera.rotationEuler.x += -Input::GetAxis("mouseY") * timedelta * 10;
        }


        trans = camera.GetProjectionMat() * camera.GetViewMat();

        Matrix model = Matrix::Translate(Matrix::One(), modelPos);

        auto projMat = camera.GetProjectionMat();
        auto viewMat = camera.GetViewMat();

        

        shaderProg.SetUniformMatrix4fv("projection", projMat.get_value_ptr());
        shaderProg.SetUniformMatrix4fv("view", viewMat.get_value_ptr());
        shaderProg.SetUniformMatrix4fv("model", model);

        //youtong->GetChildAt(0)->GetComponent<MeshRenderer>()->OnDraw(&shaderProg);

        shaderProg.SetUniformColor("lightColor", Color::Yellow());
        shaderProg.SetUniformVector3("lightPos", Vector3(1.5f, 2.0f, 1.0f));
        shaderProg.SetUniformVector3("viewPos", camera.position);

        shaderProg.SetUniformVector3("mat_ambient", { 1.0f, 0.5f, 0.31f });
        shaderProg.SetUniformVector3("mat_diffuse", { 1.0f, 0.5f, 0.31f });

        shaderProg.SetUniformFloat("mat_shininess", 32.0f);
        //shaderProg.SetUniformTexture2D("specular2d");

        shaderProg.SetUniformVector3("light.ambient", { 0.2f, 0.2f, 0.2f });
        shaderProg.SetUniformVector3("light.diffuse", { 0.5f, 0.5f, 0.5f });
        shaderProg.SetUniformVector3("light.specular", { 1.f, 1.f, 1.f });

        //shaderProg.setUniformInt("ourTexture2", 1);
        //激活0位置的纹理单元
        //shaderProg.SetUniformInt("diffuse2d", 0);
        //glActiveTexture(GL_TEXTURE0);
        //glBindTexture(GL_TEXTURE_2D, texture2d->get_id());
        shaderProg.SetUniformTexture2D("diffuse2d", "p");
        shaderProg.SetUniformTexture2D("specular2d", "specular");
        //shaderProg.SetUniformInt("specular2d", 1);
        //glActiveTexture(GL_TEXTURE1);
        //glBindTexture(GL_TEXTURE_2D, spec2d->get_id());

        glBindVertexArray(VAO);

        glDrawArrays(GL_TRIANGLES, 0, 36);

        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        glBindVertexArray(0);


        glBindVertexArray(planeVAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);

        Matrix lightModel = Matrix::One();
        lightModel = Matrix::Translate(lightModel, Vector3(1.5f, 2.0f, 1.0f));


        lightShaderProg.UseProgram();
        lightShaderProg.SetUniformMatrix4fv("projection", projMat.get_value_ptr());
        lightShaderProg.SetUniformMatrix4fv("view", viewMat.get_value_ptr());
        lightShaderProg.SetUniformMatrix4fv("model", lightModel);



        glBindVertexArray(lightVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);

        scene->OnUpdate();
        SystemInterface::PollEvents();
        Input::PollEvents();

    }

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
        cout << "stdException" << endl;
        cout << e.what() << endl;
    }

    launcher.Terminate();

    return 0;
}