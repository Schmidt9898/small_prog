import hu.ppke.itk.java.halpa.beadando.Action;
import hu.ppke.itk.java.halpa.beadando.UserInterface;
import javafx.application.Application;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class Gamegui extends Application implements UserInterface {


    private static final int TILE_SIZE = 40;
    private static final int W = 800;
    private static final int H = 600;

    private static final int X_TILES = W / 10;
    private static final int Y_TILES = H / 10;

    private Tile[][] grid = new Tile[X_TILES][Y_TILES];
    private Scene scene;

    private Parent createContent() {
        Pane root = new Pane();
        root.setPrefSize(W, H);

        for (int y = 0; y < Y_TILES; y++) {
            for (int x = 0; x < X_TILES; x++) {
                Tile tile = new Tile(x, y, 0);

                grid[x][y] = tile;
                root.getChildren().add(tile);
            }
        }
        return root;
    }


    @Override
    public void updateUI(String message) {

    }

    @Override
    public Action getAction() {
        return null;
    }

    @Override
    public void start(Stage stage) throws Exception {

    }

    private class Tile extends StackPane {
        private int x, y;
        private int id;
        private boolean isOpen = false;

        private Rectangle border = new Rectangle(TILE_SIZE - 2, TILE_SIZE - 2);
        private Text text = new Text();

        public Tile(int x, int y, int id_) {
            this.x = x;
            this.y = y;
            id=id_;
            //this.hasBomb = hasBomb;

            border.setStroke(Color.LIGHTGRAY);

            text.setFont(Font.font(18));
            text.setText(id+"");
            text.setVisible(false);

            getChildren().addAll(border, text);

            setTranslateX(x * TILE_SIZE);
            setTranslateY(y * TILE_SIZE);

            //setOnMouseClicked(e -> open());
        }


    }
}
