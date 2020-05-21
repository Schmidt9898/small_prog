package hu.ppke.itk.java.halpa.beadando;

/**
 * The interface used by the "middle" communication part to send updates to the
 * UI.
 */
public interface UserInterface {
    /**
     * Pass the updates to the User Interface to update it.
     *
     * <p>If you want you can change the type from String if you have a good
     * reason just document it.
     * <p> You can even divide this to multiple functions like `updateScores`
     * and `updateExtraObjects` `updateMap` as fits.
     *
     * @param message the message with the updates.
     */
    void updateUI(String message);

    Action getAction();
}
