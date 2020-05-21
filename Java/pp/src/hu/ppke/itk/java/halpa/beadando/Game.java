package hu.ppke.itk.java.halpa.beadando;

import java.util.ArrayList;
import java.util.List;

public class Game {
    int size = 0;
    int id_count = 1;//TODU update
    int[][] Grid = null;
    List<PlayerData> players = null;
    //List<>

    public Game(int size_) {
        players = new ArrayList<>();
        size = size_;
        Grid = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                Grid[i][j] = 0;
            }
        }

    }

    public int New_Player_init(String name) {
        int x_, y_;
        while (true) {

            x_ = 5;//(int) (Math.random() * size);
            y_ = 5;//(int) (Math.random() * size);

            if (Grid[x_][y_] == 0) {
                PlayerData temp = new PlayerData(name, x_, y_);
                temp.id = id_count;
                Grid[x_][y_] = temp.id;
                id_count++;
                players.add(temp);
                return temp.id;

            }

        }
    }

    private PlayerData getplayerbyid(int id) {
        for (int i = 0; i < players.size(); i++) {
            if (players.get(i).id == id)
                return players.get(i);
        }
        System.out.println("te fasz");
        return null;
    }

    public String Update(int id, Action act) {
        PlayerData temp = getplayerbyid(id);
        int next_x = 0, next_y = 0;
        switch (act) {
            case FORWARD:
                break;
            case TURN_LEFT:
                temp.dir = (temp.dir == 0) ? 3 : temp.dir - 1;
                break;
            case TURN_RIGHT:
                temp.dir = (temp.dir == 3) ? 0 : temp.dir + 1;
                break;
        }
        if (temp.dir == 0) {
            next_x = temp.x - 1;
            next_y = temp.y;
        }
        if (temp.dir == 1) {
            next_x = temp.x;
            next_y = temp.y - 1;
        }
        if (temp.dir == 2) {
            next_x = temp.x + 1;
            next_y = temp.y;
        }
        if (temp.dir == 3) {
            next_x = temp.x;
            next_y = temp.y + 1;
        }
        next_x = (next_x >= size) ? 0 : next_x;
        next_x = (next_x < 0) ? size - 1 : next_x;
        next_y = (next_y >= size) ? 0 : next_y;
        next_y = (next_y < 0) ? size - 1 : next_y;

        if (Grid[next_x][next_y] == 0) {

            Grid[next_x][next_y] = temp.id;
            temp.x = next_x;
            temp.y = next_y;

        } else {
            return "dead";
        }
        return "good";


    }

    public void PrintGrid() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                System.out.print(Grid[i][j] + " ");

            }
            System.out.println();
        }
    }

}
