#include "player.h"

Player::Player(PlayerCreateInfo* createInfo) {
	position = createInfo->position;
	eulers = createInfo->eulers;
}
	
void Player::update(unsigned int shader) {
	glm::vec3 forwards{
			glm::sin(glm::radians(eulers.y)) * glm::cos(glm::radians(eulers.z)),
			glm::sin(glm::radians(eulers.y)) * glm::sin(glm::radians(eulers.z)),
			glm::cos(glm::radians(eulers.y))
	};
	glm::vec3 globalUp{ 0.0f, 0.0f, 1.0f };
	glm::vec3 right{ glm::cross(forwards, globalUp) };
	glm::vec3 up{ glm::cross(right,forwards) };
	glm::mat4 view_transform{ glm::lookAt(position, position + forwards, up) };
	glUniformMatrix4fv(glGetUniformLocation(shader, "view"), 1, GL_FALSE, glm::value_ptr(view_transform));
}
