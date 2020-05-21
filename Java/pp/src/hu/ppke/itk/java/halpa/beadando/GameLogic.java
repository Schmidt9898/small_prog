package hu.ppke.itk.java.halpa.beadando;

import java.util.ArrayList;
import java.util.List;

public class GameLogic implements Runnable {
    int size = 0;
    int id_count = 1;//TODU update
    int[][] Grid = null;
    List<PlayerData> players = new ArrayList<>();
    MessageHandler messageHandler = null;

    Boolean isrun = true;


    public GameLogic(int size_, MessageHandler ms) {
        messageHandler = ms;
        size = size_;
        Grid = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                Grid[i][j] = 0;
            }
        }

    }

    public String New_Player_init(String name) {
        int x_, y_;
        while (true) {

            x_ = (int) (Math.random() * size);
            y_ = (int) (Math.random() * size);

            if (Grid[x_][y_] == 0) {
                PlayerData temp = new PlayerData(name, x_, y_);
                temp.id = id_count;
                id_count++;
                players.add(temp);
                return temp.toString();//visszatér az új játékos adattal

            }

        }
    }

    public void New_Player() {
    }


    @Override
    public void run() {
        while (true) {
            synchronized (isrun) {
                if (!isrun) break;
            }

            try {
                Thread.sleep(2000);
            } catch (InterruptedException e) {
                e.printStackTrace();
                return;
            }
            synchronized (players) {
                List<String> update = new ArrayList<>();//lista amit közölni kell a játékosokkal
                List<new_position_id> new_positions = new ArrayList<>();//kiszámolt új pozíciók
                ArrayList<Integer> dead_id = new ArrayList<>();

                for (PlayerData p : players) {
                    new_positions.add(p.Calculat_mystep(size));
                }
                //Megnézi, hogy van e olyan két játékos aki ugyan arra a pontra szeretne lépni
                //ha igen akkor mind a ketten meghalnak
                for (int i = 0; i < new_positions.size(); i++) {
                    for (int j = 0; j < new_positions.size(); j++) {
                        if (i == j) continue;

                        if (new_positions.get(i).x == new_positions.get(j).x && new_positions.get(i).y == new_positions.get(j).y) {
                            if (!dead_id.contains(new_positions.get(i).id))
                                dead_id.add(new_positions.get(i).id);
                            if (!dead_id.contains(new_positions.get(j).id))
                                dead_id.add(new_positions.get(j).id);
                        }
                    }
                }
                for (new_position_id np : new_positions) {
                    if (Grid[np.x][np.y] != 0) {
                        //update.add("1_"+np.id);
                        if (!dead_id.contains(np.id))
                            dead_id.add(np.id);
                    }

                }
                for (int i = 0; i < new_positions.size(); i++) {
                    if (dead_id.contains(new_positions.get(i).id)) {
                        new_positions.remove(i);
                        update.add("1_" + new_positions.get(i).id);
                        i--;
                    }
                }
                for (PlayerData playerdata : players) {
                    for (new_position_id p : new_positions) {
                        if (playerdata.id == p.id) {
                            playerdata.Update(p);
                            update.add("2_" + playerdata.toString());// 2_nema_id_x_y
                            break;
                        }
                    }
                }
                update.add("3");
                String[] valami = update.toArray(String[]::new);
                messageHandler.handle(valami);//TODO gondold végig


            }


            //TODO
            /*
             * várna pár másodpercet és bekérné for ciklussal az összes lépést
             * kiértékeli a lépéseket
             * elküldi az eredményeket
             * exception
             * */


        }
    }


    public void updatePlayer(int id, Action act) {
        for (PlayerData p : players) {
            if (p.id == id)
                p.action = act;
        }
    }
}
