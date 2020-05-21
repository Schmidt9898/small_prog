#ifndef INPUTMANAGGER_H_INCLUDED
#define INPUTMANAGGER_H_INCLUDED
class InputManagger;
///Ezt az osztályt azért hoztam létre hogy kezeljen minden inputot és az inputokhoz lehessen delegálni fügvényeked
///ám késöbb amikor már sok idõt beleöltem jöttem rá hogy csak is globális változókkal tud komunikálni ezért majdnem fülösleges volt
/// de legalább szépen mutat
/*
Megkapjuk a lenyomitt gombot és a nekünk átadott függvénypointert meghívjuk, a megfelelõ idõpontban valamint számoljuk az egér helyzetét.
*/

struct BTN{
bool down=false;
int key=-1;

BTN(){};
BTN(int key_):key(key_){};

void (*SingleAction)() = nullptr;
void (*Action)()= nullptr;

private:
    void ActionHandler(int key_,int act){
    if(key!=key_)
        return;
    if(act==GLFW_PRESS)
    {
            if(!down)
            {
                down=true;
                if(SingleAction!=nullptr)
                    SingleAction();
                //if(Action!=nullptr)
                  //  Action();

            }/*else
            {
                if(Action!=nullptr)
                    Action();
            }*/
    }else if(act==GLFW_RELEASE)
        down=false;
    }
    void ActionContinue()
    {
        if(down && Action!=nullptr)
        {
            Action();
        }
    }

    friend class InputManagger;
};

class InputManagger{
public:
    glm::vec2 mouse_position;
    void (*Mouse_Hover)()= nullptr;

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

    }
    void update_mouse(int key,int act)
    {
        btn_mouseright.ActionHandler(key,act);
        btn_mouseleft.ActionHandler(key,act);
    }
    void update_continius(GLFWwindow* window,unsigned int SCR_WIDTH,unsigned int SCR_HEIGHT)
    {
        double x,y;
        glfwGetCursorPos(window,&x,&y);
        mouse_position.x= 2.0/SCR_WIDTH*x-1.0;
        mouse_position.y= 2.0/SCR_HEIGHT*y-1.0;
        mouse_position.y*=-1;
        if(Mouse_Hover!=nullptr)
        {
            Mouse_Hover();
        }




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

    }


};

#endif // INPUTMANAGGER_H_INCLUDED
