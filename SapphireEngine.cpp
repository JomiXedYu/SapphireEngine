#pragma once
#include <ThirdParty/glad/glad.h>
#include <ThirdParty/glfw/include/GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <CoreLib/File.h>


#include <SapphireEngine/Private/BaseInterface.h>


#include <format>
#include <CoreLib/Exception.h>
#include <SapphireEngine/_include.h>

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

    //顶点， 颜色， UV
    //float vertices[] = {
    //	-0.5f,  0.5f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,    0.0f, 1.0f,  //左上
    //	 0.5f,  0.5f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,    1.0f, 1.0f,  //右上
    //	 0.5f, -0.5f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,    1.0f, 0.0f,  //右下
    //	-0.5f, -0.5f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,    0.0f, 0.0f,  //左下
    //};
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

    uint32_t texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    string texturePath = Application::DataFolder() + "\\texture";
    string shaderPath = Application::DataFolder() + "\\shader";

    Bitmap* bp = Resource::LoadBitmap(texturePath + "\\p.jpg");


    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bp->get_width(), bp->get_height(), 0, GL_RGB, GL_UNSIGNED_BYTE, bp->GetNativeData());
    glGenerateMipmap(GL_TEXTURE_2D);

    delete(bp); bp = nullptr;

    glBindTexture(GL_TEXTURE_2D, 0);



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

    //创建顶点着色器
    String shaderSource = File::ReadAllText(shaderPath + "\\StandardVertexShader.glsl");
    Shader vertexShader = Shader::CreateVetexShader("StandardVertexShader", shaderSource);
    cout << "顶点着色器创建完毕" << endl;
    //创建片段着色器
    String fragsrc = File::ReadAllText(shaderPath + "\\DefaultFragmentShader.glsl");
    Shader fragmentShader = Shader::CreateFragmentShader("DefaultFragmentShader", fragsrc);
    cout << "片元着色器创建完毕" << endl;

    ShaderProgram lightShaderProg;
    Shader lightShader = Shader::CreateFragmentShader("LightShader", File::ReadAllText(shaderPath + "\\LightFragmentShader.glsl"));
    lightShaderProg.AttachShader(vertexShader);
    lightShaderProg.AttachShader(lightShader);
    lightShaderProg.Link();

    //创建着色器程序
    ShaderProgram shaderProg;
    shaderProg.AttachShader(vertexShader);
    shaderProg.AttachShader(fragmentShader);
    shaderProg.Link();

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
    //camera.backgroundColor = Color::Blue();
    float timedelta = 0;
    float prevdelta = 0;
    //渲染循环
    while (!Application::IsQuit())
    {
        prevdelta = Time::TimeCount();

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

        camera.position += camera.Forward() * vert * 0.03f;
        camera.position += camera.Right() * -hori * 0.03f;

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
            camera.rotation.AddEulerY(Input::GetAxis("mouseX") * timedelta * 100);
            camera.rotation.AddEulerX(-Input::GetAxis("mouseY") * timedelta * 100);
        }

        Logger::Info() << camera.position.ToString();
        Logger::Info() << camera.GetViewMat().ToString();

        trans = camera.GetProjectionMat() * camera.GetViewMat();

        Matrix model(1);
        Matrix proj
        (
            2.4, 0.0, 0.0, 0.0,
            0.0, 2.4, 0.0, 0.0,
            0.0, 0.0, -1.0, -0.2,
            0.0, 0.0, -1.0, 0
        );
        shaderProg.SetUniformMatrix4fv("projection", camera.GetProjectionMat().get_value_ptr());
        shaderProg.SetUniformMatrix4fv("view", camera.GetViewMat().get_value_ptr());
        shaderProg.SetUniformMatrix4fv("model", model);

        shaderProg.SetUniformColor("lightColor", Color::Yellow());
        shaderProg.SetUniformVector3("lightPos", Vector3(1.5f, 2.0f, 1.0f));
        shaderProg.SetUniformVector3("viewPos", camera.position);

        //shaderProg.setUniformInt("ourTexture2", 1);
        //激活0位置的纹理单元
        shaderProg.SetUniformInt("ourTexture", 0);
        glActiveTexture(GL_TEXTURE0);
        //绑定贴图至0位置
        glBindTexture(GL_TEXTURE_2D, texture);
        //glActiveTexture(GL_TEXTURE1);
        //glBindTexture(GL_TEXTURE_2D, texture2);

        glBindVertexArray(VAO);

        glDrawArrays(GL_TRIANGLES, 0, 36);

        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        glBindVertexArray(0);


        glBindVertexArray(planeVAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);

        Matrix lightModel;
        lightModel = Matrix::Translate(lightModel, Vector3(1.5f, 2.0f, 1.0f));


        lightShaderProg.UseProgram();
        lightShaderProg.SetUniformMatrix4fv("projection", camera.GetProjectionMat().get_value_ptr());
        lightShaderProg.SetUniformMatrix4fv("view", camera.GetViewMat().get_value_ptr());
        lightShaderProg.SetUniformMatrix4fv("model", lightModel);

        glBindVertexArray(lightVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);

        SystemInterface::PollEvents();
        Input::PollEvents();

        timedelta = Time::TimeCount() - prevdelta;
    }

}

int main() {

    SapphireEngine::EngineManager::Init();

    try {
        run();
    }
    catch (std::exception& e) {
        cout << "stdException" << endl;
        cout << e.what() << endl;
    }

    SapphireEngine::EngineManager::Term();


    return 0;
}