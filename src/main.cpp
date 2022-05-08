#include "main.h"
#include "imgui.h"
#include <windows.h>
#include "GLFW\glfw3.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <iostream>
#include <string>
using namespace std;

void error_callback(int error, const char* description) {
	fputs(description, stderr);
}

void newCalcWindow() {

	ImGui::Begin("New Calculator");
	ImGui::Text("New basic arithmetic calculator");
	static string expressionView = "";
	static float floatyExpr[256] = {};
	static int order[256] = {};
	static float solution = 0;
	static string numbers = "";
	float num1 = 0.f;
	float num2 = 0.f;
	bool assigned = false;
	static int x = 0;
	ImGui::TextWrapped("Expression: %s", expressionView.c_str());

	ImGui::TextWrapped("Result:     %f", solution);
	
	if (ImGui::Button("7", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_Keypad7)) {
		expressionView += "7";
		numbers += "7";
	}
	ImGui::SameLine();
	if (ImGui::Button("8", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_Keypad8)) {
		expressionView += "8";
		numbers += "8";
	}
	ImGui::SameLine();
	if (ImGui::Button("9", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_Keypad9)) {
		expressionView += "9";
		numbers += "9";
	}
	ImGui::SameLine();
	if (ImGui::Button("C", ImVec2(50, 50))) {
		expressionView.erase();
		numbers.erase();
		for (int i = 0; i < 256; i++) {
			floatyExpr[i] = 0;
			order[i] = 0;
		}
	}
	if (ImGui::Button("4", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_Keypad4)) {
		expressionView += "4";
		numbers += "4";
	}
	ImGui::SameLine();
	if (ImGui::Button("5", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_Keypad5)) {
		expressionView += "5";
		numbers += "5";
	}
	ImGui::SameLine();
	if (ImGui::Button("6", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_Keypad6)) {
		expressionView += "6";
		numbers += "6";
	}
	ImGui::SameLine();
	if (ImGui::Button("-", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_KeypadSubtract)) {
		expressionView += "-";
		floatyExpr[x] = atof(numbers.c_str());
		order[x] = 6;
		x++;
		numbers = "";
	}
	if (ImGui::Button("1", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_Keypad1)) {
		expressionView += "1";
		numbers += "1";
	}
	ImGui::SameLine();
	if (ImGui::Button("2", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_Keypad2)) {
		expressionView += "2";
		numbers += "2";
	}
	ImGui::SameLine();
	if (ImGui::Button("3", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_Keypad3)) {
		expressionView += "3";
		numbers += "3";
	}
	ImGui::SameLine();
	if (ImGui::Button("+", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_KeypadAdd)) {
		expressionView += "+";
		floatyExpr[x] = atof(numbers.c_str());
		order[x] = 5;
		x++;
		numbers = "";
	}
	if (ImGui::Button("0", ImVec2(108, 50)) || ImGui::IsKeyPressed(ImGuiKey_Keypad0)) {
		expressionView += "0";
		numbers += "0";
	}
	ImGui::SameLine();
	if (ImGui::Button(".", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_KeypadDecimal)) {
		expressionView += ".";
		numbers += ".";
	}
	ImGui::SameLine();
	if (ImGui::Button("Enter", ImVec2(50, 50)) || ImGui::IsKeyPressed(ImGuiKey_KeypadEnter)) {
		floatyExpr[1] = atof(numbers.c_str());
		for (int i = 0; i < 5; i++) {
			cout << floatyExpr[i];
			cout << "\n";
		}

		solution = extra::expressionCalculator(floatyExpr, order);
		x = 0;
	}
	
	ImGui::End();
}


void guiWindows() {
	// This is the gui drawing thing where I put the code for running ImGui windows
	//basicCalcwindow();
	ImGui::ShowDemoWindow();
	newCalcWindow();
}

void windowInit() {

	//Setting the error callback
	glfwSetErrorCallback(error_callback);

	//Setting the glsl version very important
	const char* glsl_version = "#version 130";

	//If glfw doesn't initiate it will exit with a failure code
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
		return;
	}

	//Setting the window size and also creating it along with its parameters
	GLFWwindow* window = glfwCreateWindow(1280, 720, "Calculator", NULL, NULL);

	//If there is no window it will terminate providing a window.
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

	//Application loop
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