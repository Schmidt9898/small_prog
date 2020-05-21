package hu.ppke.itk.java.halpa.beadando;

/**
 * The interface used by the UI to inform the game about events.
 */
public interface MessageHandler {
    /**
     * All relevant events from the UI should be transformed to a simple format
     * that the can be consumed by the "communicatino layer".
     *
     * <p> The parameter should be something uniform and not some event type
     * from JavaFX.
     * <p> However you can use your own event descriptor class, that might
     * be easier to parse.
     *
     * @param message The description of the event happened e.g. the pressed
     *                character, typed string etc.
     */
    void handle(String message);

    /**
     * Special case if the UI knows what happened, but you can use your own
     * event descriptor class.
     *
     * @param step
     */
    void handle(Action step);

    void handle(String[] msg);
}
