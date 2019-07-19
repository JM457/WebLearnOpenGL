#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

// function declaration
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processInput(GLFWwindow* window);

//setting...
const unsigned int width = 800;
const unsigned int height = 600;



int main(void) {


// inititialize window using GLFW (glfw responsible for output and input on operating systems)
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
// create window with GLFW
	GLFWwindow* window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);

	if (window==NULL)
	{
		std::cout << "failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

// initialize GLAD and start calling openGL function

	if (! gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize glad" << std::endl;
		return -2;
	}
// gl rendering window, inside the glfw window
	glViewport(0, 0, width, height);


// rendering loop
	while (!glfwWindowShouldClose(window))
	{
		// input
		processInput(window);

		//rendering commands here
		glClearColor(0.2f,0.3f,0.3f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//check the call events and swap the buffer
		glfwSwapBuffers(window);
		glfwPollEvents();
	}


//clear the memory used by glfw
	glfwTerminate();
	return 0;

}


// function definition
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}