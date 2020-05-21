package hu.ppke.itk.java.halpa.beadando;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// szálként vár konzol inputot, updateUI()-val frissít
public class GameTextUI implements UserInterface, Runnable {
    int[][] grid;
    int size = 10;
    private Action myNextStep = Action.FORWARD;

    public GameTextUI() {
        this.grid = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = 0;
            }
        }
    }

    @Override
    public void run() {
        System.out.println("Welcome Screen of TextUI");
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        while (!Thread.interrupted()) {
            try {
                String str = reader.readLine().toLowerCase();
                synchronized (myNextStep) {
                    if (str.contains("a"))
                        myNextStep = Action.TURN_LEFT;
                    else if (str.contains("d"))
                        myNextStep = Action.TURN_RIGHT;
                    else
                        myNextStep = Action.FORWARD;
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    @Override
    public void updateUI(String msg) {
        String[] array = msg.split("_");
        switch (array[0]) {
            case "1": // meghaltam
                System.out.println("I am dead now.");
                break;
            case "3": // kirajzolás
                printGrid();
                break;
            case "0": // frissítés
            case "2":
                grid[Integer.parseInt(array[3])][Integer.parseInt(array[4])] = Integer.parseInt(array[2]);
                break;
        }
    }

    @Override
    public Action getAction() {
        return myNextStep;
    }

    void printGrid() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                System.out.print(grid[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public Action getMyNextStep() {
        return myNextStep;
    }
}
