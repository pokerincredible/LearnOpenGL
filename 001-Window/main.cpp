#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

using namespace std;

// 回调函数，当窗口大小被调整时被调用
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
// 检查Esc按键是否按下
void processInput(GLFWwindow* window);

int main()
{
	
	glfwInit(); // 初始化GLFW	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // 主版本号
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5); // 次版本号
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 使用核心模式(Core-profile)

	// 创建一个窗口对象，宽/长/窗口名称
	GLFWwindow* window = glfwCreateWindow(1280, 720, "001Window", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// 通知GLFW将此窗口的上下文设置为当前线程的主上下文
	glfwMakeContextCurrent(window);

	// glad管理OpenGL函数指针（由GLFW提供）的，调用OpenGL函数前需要初始化glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// 设置视口（渲染窗口）大小
	glViewport(0, 0, 1600, 1200);

	// 注册回调函数
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// 查看电脑版本号
	const char* version = (const char*)glGetString(GL_VERSION);
	cout << "OpenGL Version: " << version << endl;

	// 渲染循环, 检查GLFW是否被要求退出
	while (!glfwWindowShouldClose(window))
	{
		// 输入事件
		processInput(window);
		// 渲染指令
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// 交换缓冲, 检测并调用事件(按键按下/释放, 鼠标移动)
		glfwPollEvents();
		glfwSwapBuffers(window);		
	}

	// 释放资源
	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_TRUE)
		glfwSetWindowShouldClose(window, true);
}


