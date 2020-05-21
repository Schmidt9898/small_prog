package hu.ppke.itk.java.halpa.beadando;

public class PlayerData {
    String name = "none";//msgid_id_name   1_3_laci
    int id = -1;                  // msgid_id_dir   2_3_4
    int dir = 0; // direction 0 = balra 1 = fel 2 = jobra 3 = le
    Action action = Action.FORWARD;
    int x = 0, y = 0;//last step;

    public PlayerData(String name_, int x_, int y_) {
        name = name_;
        x = x_;
        y = y_;
    }

    public new_position_id Calculat_mystep(int grid_size) {
        // new_position_id temp = new new_position_id();
        int next_x = 0, next_y = 0;
        System.out.println(action);
        switch (action) {
            case FORWARD:

                break;
            case TURN_LEFT:

                dir = (dir == 0) ? 3 : dir - 1;
                break;
            case TURN_RIGHT:
                dir = (dir == 3) ? 0 : dir + 1;
                break;
        }
        if (dir == 0) {
            next_x = x - 1;
            next_y = y;
        }
        if (dir == 1) {
            next_x = x;
            next_y = y - 1;
        }
        if (dir == 2) {
            next_x = x + 1;
            next_y = y;
        }
        if (dir == 3) {
            next_x = x;
            next_y = y + 1;
        }
        next_x = (next_x >= grid_size) ? 0 : next_x;
        next_x = (next_x < 0) ? grid_size - 1 : next_x;
        next_y = (next_y >= grid_size) ? 0 : next_y;
        next_y = (next_y < 0) ? grid_size - 1 : next_y;

        return new new_position_id(id, next_x, next_y);
    }

    public void Update(new_position_id p) {
        x = p.x;
        y = p.y;
    }

    @Override
    public String toString() {
        return name + "_" + id + "_" + x + "_" + y;
        // nema_id_x_y
    }
}
