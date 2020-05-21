package com.company;

public interface MessageHandler {
    //PlayerCommunicator com=null;
   // UserInterface ui=null;
    //public void init();

    public void handle(String msg);
    public void handle(String[] msg);
    public void handle(Action act);
}
