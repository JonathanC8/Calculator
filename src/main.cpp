#include "main.h"
#include "imgui.h"
#include <windows.h>
#include "GLFW\glfw3.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <iostream>
#include <string>
using namespace std;

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

	if (ImGui::Button("Calculate")) {

		double inputA = atof(inputAa);
		double inputB = atof(inputBa);
		char op = inputOp[0];

		output = basicCalculator(inputA, inputB, op);

	}

	ImGui::Text("Output: %f", output);

	ImGui::End();
}

void newcalcbuttons() {
	
}

void newCalcWindow() {

	ImGui::Begin("New Calculator");
	ImGui::Text("New basic arithmetic calculator");
	static string expression = "";
	static float total = 0;
	bool assigned = false;
	ImGui::Text("Expression: %s", expression.c_str());

	ImGui::TextWrapped("Total:     %f", total);
	
	if (ImGui::Button("7", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_Keypad7)) {
		expression += "7";
	}
	ImGui::SameLine();
	if (ImGui::Button("8", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_Keypad8)) {
		expression += "8";
	}
	ImGui::SameLine();
	if (ImGui::Button("9", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_Keypad9)) {
		expression += "9";
	}
	ImGui::SameLine();
	if (ImGui::Button("C", ImVec2(50, 50))) {
		expression.erase();
	}
	if (ImGui::Button("4", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_Keypad4)) {
		expression += "4";
	}
	ImGui::SameLine();
	if (ImGui::Button("5", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_Keypad5)) {
		expression += "5";
	}
	ImGui::SameLine();
	if (ImGui::Button("6", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_Keypad6)) {
		expression += "6";
	}
	ImGui::SameLine();
	if (ImGui::Button("-", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_KeypadSubtract)) {
		expression += "-";
	}
	if (ImGui::Button("1", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_Keypad1)) {
		expression += "1";
	}
	ImGui::SameLine();
	if (ImGui::Button("2", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_Keypad2)) {
		expression += "2";
	}
	ImGui::SameLine();
	if (ImGui::Button("3", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_Keypad3)) {
		expression += "3";
	}
	ImGui::SameLine();
	if (ImGui::Button("+", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_KeypadAdd)) {
		expression += "+";
	}
	if (ImGui::Button("0", ImVec2(108, 50)) || ImGui::IsKeyPressed(ImGuiKey_Keypad0)) {
		expression += "0";
	}
	ImGui::SameLine();
	if (ImGui::Button(".", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_KeypadDecimal)) {
		expression += ".";
	}
	ImGui::SameLine();
	if (ImGui::Button("Calculate", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_KeypadEnter)) {
		int arraySize = expression.size();
		static char inputAa[3]={};
		static char inputBa[2]={};
		int	dividingPoint = 0;
		
		int z = 0;
		for (int x = 0; x <= arraySize; x++) {
			if (expression[x] == '+') {
				dividingPoint = x;
			}
			if (dividingPoint != 0) {
				for (int y = 0; y <= dividingPoint; y++) {
					inputAa[y] = expression[y];
				}
			}
			if (x > dividingPoint) {
				inputBa[z] = expression[x];
				z++;
			}
		}
		char op = expression[dividingPoint];
		double inputA = atof(inputAa);
		double inputB = atof(inputBa);
		total = basicCalculator(inputA, inputB, op);
		ImGui::Text("Debug Expression: %s", expression.c_str());
		ImGui::Text("Debug A: %f", inputA);
		ImGui::Text("Debug B: %s", inputBa);
		
	}
	
	ImGui::End();
}


void guiWindows() {
	// This is the gui drawing thing where I put the code for running ImGui windows
	basicCalcwindow();
	ImGui::ShowDemoWindow();
	newCalcWindow();
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


