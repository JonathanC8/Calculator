#include "main.h"
#include "imgui.h"
#include <windows.h>
#include "GLFW\glfw3.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <iostream>

void MedModRun();
double basicCalculator(double inputA, double inputB, char op);

void error_callback(int error, const char* description) {
	fputs(description, stderr);
}

void basicCalcwindow() {
	ImGui::Begin("Calculator");

	ImGui::Text("Basic operations calculator");
	static char inputAa[128] = {};
	static char inputBa[128] = {};
	static char inputOp[2] = { };
	size_t sizea = sizeof(inputAa);
	size_t sizeb = sizeof(inputOp);
	size_t sizec = sizeof(inputBa);

	ImGui::InputText("First Number", inputAa, sizea); ImGui::InputText("Operator", inputOp, sizeb); ImGui::InputText("Second Number", inputBa, sizec);
	static double output = 0;

	if (ImGui::Button("Button")) {

		double inputA = atof(inputAa);
		double inputB = atof(inputBa);
		char op = inputOp[0];

		output = basicCalculator(inputA, inputB, op);

	}

	ImGui::Text("Output: %f", output);

	ImGui::End();
}


void guiWindows() {
	// This is the gui drawing thing where I put the code for running ImGui windows
	basicCalcwindow();
}

void windowInit() {

	glfwSetErrorCallback(error_callback);

	const char* glsl_version = "#version 130";

	if (!glfwInit()) {
		exit(EXIT_FAILURE);
		return;
	}

	GLFWwindow* window = glfwCreateWindow(1280, 720, "Calculator", NULL, NULL);

	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
		return;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();

	//ImGui GLFW initialization
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);

	//sets background color variable
	ImVec4 clear_color = ImVec4(0.20f, 0.20f, 0.20f, 0.20f);

	while (!glfwWindowShouldClose(window)) {

		glfwPollEvents();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		guiWindows(); //calls the drawings


		//Window rendering and color setting
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);

	}

	glfwDestroyWindow(window);
	glfwTerminate();

}


int main(int, char**) {
	windowInit();
	
	return 0;
}