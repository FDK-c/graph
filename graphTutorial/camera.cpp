#ifndef CAMERA_CPP
#define CAMERA_CPP

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

using namespace std;

enum CAMERA_MOVEMENT {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
};

const float YAW = -90.f;
const float PITCH = 0.0f;

const float SPEED = 2.5f;
const float SENSITIVITY = 0.05f;

class camera
{
public:
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 5.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 cameraRight = glm::vec3(1.0f, 0.0f, 0.0f);
	glm::vec3 WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);

	float cameraYaw;
	float cameraPitch;

	float movementSpeed;
	float mouseSensitivity;

	camera()
	{
		cameraYaw = YAW;
		cameraPitch = PITCH;

		movementSpeed = SPEED;
		mouseSensitivity = SENSITIVITY;

		updateCameraVectors();
	}

	glm::mat4 GetViewMatrix()
	{
		return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	}

	void ProcessKeyboard(CAMERA_MOVEMENT direction, float deltaTime)
	{
		float velocity = movementSpeed * deltaTime;
		if (direction == FORWARD)
			cameraPos += cameraFront * velocity;
		if (direction == BACKWARD)
			cameraPos -= cameraFront * velocity;
		if (direction == LEFT)
			cameraPos -= cameraRight * velocity;
		if (direction == RIGHT)
			cameraPos += cameraRight * velocity;
	}

	// processes input received from a mouse input system. Expects the offset value in both the x and y direction.
	void ProcessMouseMovement(float xoffset, float yoffset)
	{
		xoffset *= mouseSensitivity;
		yoffset *= mouseSensitivity;

		cameraYaw += xoffset;
		cameraPitch += yoffset;

		// make sure that when pitch is out of bounds, screen doesn't get flipped
		if (cameraPitch > 89.0f)
			cameraPitch = 89.0f;
		if (cameraPitch < -89.0f)
			cameraPitch = -89.0f;

		updateCameraVectors();
	}

private:
	void updateCameraVectors()
	{
		glm::vec3 front = glm::vec3(1.0f);
		front.x = cos(glm::radians(cameraYaw)) * cos(glm::radians(cameraPitch));
		front.y = sin(glm::radians(cameraPitch));
		front.z = sin(glm::radians(cameraYaw)) * cos(glm::radians(cameraPitch));
		cameraFront = glm::normalize(front);

		cameraRight = glm::normalize(glm::cross(cameraFront, WorldUp));
		cameraUp = glm::normalize(glm::cross(cameraRight, cameraFront));
	}
};
#endif