package hu.ppke.itk.java.halpa.beadando;

/**
 * Interface that determine the API that used by GameLogic to get steps from
 * players and send updates about the state.
 */
public interface PlayerCommunicator {

    /**
     * Access the step the player will take in this turn.
     *
     * @return The (last pressed) step of this turn. Either FORWARD, or TURN_**.
     */
    Action getStep();

    /**
     * Te GameLogic can send updates to players after each step, or anytime.
     *
     * @param message The actual message to be sent. If you want to send something
     *                other than String you can change this, but both local and
     *                network communication must use this interface.
     */
    void updateState(String message);

    // If you want serialize stuff you can use this version as well.
    // void updateState(String header, Serializable obj);

}
