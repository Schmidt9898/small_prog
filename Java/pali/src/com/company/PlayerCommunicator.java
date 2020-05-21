package com.company;

public interface PlayerCommunicator {

    //public MessageHandler mh = null;
    //public GameLogic gamelogic = null;
    //public void init(MessageHandler mh);

    public Action GetStep();
    public void UpdateState(String msg);


}
