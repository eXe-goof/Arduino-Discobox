import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.awt.image.WritableRaster;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Exe implements IDetector {

    public static BufferedImage image;

    static String content = "";
    static List<Integer> lines = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        image = ImageIO.read(new File("C:\\Users\\.exe\\Downloads\\eee_0.png"));
        int index = 0;
        System.out.println("exe");
        WritableRaster raster = image.getRaster();
        for (int y = 0; y < image.getHeight(); y++) {
            for (int x = 0; x < image.getWidth(); x++) {
                if (raster.getSample(x,y,0) == 255) {
                    content = content + "1";
                } else {
                    content = content + "0";
                }
            }
            //System.out.println(y + "/" + image.getHeight());
            if (content.contains(line)) {
                System.out.println("Line detected at: " + y);
                lines.add(y);
                lines.get(0);
            }
            content = "";
        }

        //System.out.println("end");

        Line line = new Line(263,263);

    }

}
