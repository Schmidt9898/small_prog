#ifndef INPUTMANAGGER_H_INCLUDED
#define INPUTMANAGGER_H_INCLUDED

#include <functional>
class InputManagger;
///Ezt az osztályt azért hoztam létre hogy kezeljen minden inputot és az inputokhoz lehessen delegálni fügvényeket.
///ám késöbb amikor már sok idõt beleöltem jöttem rá hogy csak is globális változókkal tud komunikálni ezért majdnem fülösleges volt
/// de legalább szépen mutat
/// Nagy Balázs javaslata volt hogy használjak placeholder eket, helyette használtam std::functiont ami jobb megoldás lett
///így már egyszerüen működik.
/*
Megkapjuk a lenyomitt gombot és a nekünk átadott függvénypointert meghívjuk, a megfelelõ idõpontban valamint számoljuk az egér helyzetét.
*/


    /// Minta
    ///int k=0;
    ///inputmanagger.s_down.SingleAction=[&k]{k++;};

struct BTN{
bool down=false;
int key=-1;
bool isActive=false;

BTN(){};
BTN(int key_):key(key_){
SingleAction = []{};
Action = []{};

};

std::function<void()> SingleAction;
std::function<void()> Action;


private:
    void ActionHandler(int key_,int act){
    if(key!=key_)
        return;
    if(act==GLFW_PRESS)
    {
            if(!down)
            {
                down=true;
                    SingleAction();

            }
    }else if(act==GLFW_RELEASE)
        down=false;
    }
    void ActionContinue()
    {
        if(down)
        {
            Action();
        }
    }

    friend class InputManagger;
};

class InputManagger{
public:
    glm::vec2 mouse_position;
    float lastX =  800.0f / 2.0;  // kezdeti eger pozicio
    float lastY =  600.0 / 2.0;   // kezdeti eger pozicio
    float Pitch =0;
    float Yaw=0;
    bool firstMouse=true;
    //std::function<void()>Pre_update=[]{};
    std::function<void()>Mouse_Hover=[]{};

    BTN right=BTN(GLFW_KEY_RIGHT);
    BTN left=BTN(GLFW_KEY_LEFT);
    BTN up=BTN(GLFW_KEY_UP);
    BTN down=BTN(GLFW_KEY_DOWN);
    BTN enter=BTN(GLFW_KEY_ENTER);
    BTN w_up=BTN(GLFW_KEY_W);
    BTN s_down=BTN(GLFW_KEY_S);
    BTN a_left=BTN(GLFW_KEY_A);
    BTN d_right=BTN(GLFW_KEY_D);

    BTN space=BTN(GLFW_KEY_SPACE);
    BTN shift=BTN(GLFW_KEY_LEFT_SHIFT);

    BTN btn_e=BTN(GLFW_KEY_E);
    BTN btn_r=BTN(GLFW_KEY_R);
    BTN btn_q=BTN(GLFW_KEY_Q);
    BTN btn_f=BTN(GLFW_KEY_F);
    BTN btn_c=BTN(GLFW_KEY_C);
    BTN btn_t=BTN(GLFW_KEY_T);
    BTN btn_mouseright=BTN(GLFW_MOUSE_BUTTON_RIGHT);
    BTN btn_mouseleft=BTN(GLFW_MOUSE_BUTTON_LEFT);
    BTN esc=BTN(GLFW_KEY_ESCAPE);



    void update_keys(int key,int act)
    {
        right.ActionHandler(key,act);
        left.ActionHandler(key,act);
        up.ActionHandler(key,act);
        down.ActionHandler(key,act);
        enter.ActionHandler(key,act);
        w_up.ActionHandler(key,act);
        s_down.ActionHandler(key,act);
        a_left.ActionHandler(key,act);
        d_right.ActionHandler(key,act);
        space.ActionHandler(key,act);
        btn_e.ActionHandler(key,act);
        btn_r.ActionHandler(key,act);
        btn_q.ActionHandler(key,act);
        btn_f.ActionHandler(key,act);
        btn_c.ActionHandler(key,act);
        btn_t.ActionHandler(key,act);
        esc.ActionHandler(key,act);
        shift.ActionHandler(key,act);

    }
    void update_mouse(int key,int act)
    {
        btn_mouseright.ActionHandler(key,act);
        btn_mouseleft.ActionHandler(key,act);
    }
    void update_continius(GLFWwindow* window,unsigned int SCR_WIDTH,unsigned int SCR_HEIGHT)
    {
        double xpos,ypos;
        glfwGetCursorPos(window,&xpos,&ypos);
        mouse_position.x= 2.0/SCR_WIDTH*xpos-1.0;
        mouse_position.y= 2.0/SCR_HEIGHT*ypos-1.0;
        mouse_position.y*=-1;

        if (firstMouse)
        {
            lastX = xpos;
            lastY = ypos;
            firstMouse = false;
        }

        Yaw = xpos - lastX;
        Pitch = lastY - ypos; // reversed since y-coordinates go from bottom to top

        lastX = xpos;
        lastY = ypos;

        Mouse_Hover();





        right.ActionContinue();
        left.ActionContinue();
        up.ActionContinue();
        down.ActionContinue();
        enter.ActionContinue();
        w_up.ActionContinue();
        s_down.ActionContinue();
        a_left.ActionContinue();
        d_right.ActionContinue();
        space.ActionContinue();
        btn_e.ActionContinue();
        btn_r.ActionContinue();
        btn_q.ActionContinue();
        btn_f.ActionContinue();
        btn_c.ActionContinue();
        btn_t.ActionContinue();
        btn_mouseright.ActionContinue();
        btn_mouseleft.ActionContinue();
        shift.ActionContinue();

    }


};

#endif // INPUTMANAGGER_H_INCLUDED
