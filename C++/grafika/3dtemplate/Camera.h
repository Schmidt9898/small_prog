#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

float Clamp(float x,float max,float min);


// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};
class Camera
{
    private:
    // Calculates the front vector from the Camera's (updated) Euler Angles




   public :
    // Camera Attributes
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;
    // Euler Angles
    float Yaw=-90.0f;
    //float maxPitch=90,minPitch=-90;
    float Pitch=0.0f;
    // Camera options
    //float MovementSpeed;
    //float MouseSensitivity;
    float Zoom;
    Camera(glm::vec3 position)
    {
        Position = position;
        WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
        Front = glm::vec3(0.0f, 0.0f, -1.0f);
        updateCameraVectors();
    }
       glm::mat4 GetViewMatrix()
    {
        return glm::lookAt(Position, Position + Front, Up);
    }

    void LookAtthis(glm::vec3 to_pos){};

    void updateCameraVectors()
    {
        // Calculate the new Front vector
        glm::vec3 front;
        front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        front.y = sin(glm::radians(Pitch));
        front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        Front = glm::normalize(front);
        // Also re-calculate the Right and Up vector
        Right = glm::normalize(glm::cross(Front, WorldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        Up    = glm::normalize(glm::cross(Right, Front));
    }





};

#endif // CAMERA_H_INCLUDED
