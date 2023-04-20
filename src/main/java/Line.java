import java.awt.image.WritableRaster;

public class Line implements IDetector {

    final int topLine;
    final int bottomLine;

    private final WritableRaster raster;

    String pointer = "";

    public Line(int topLine, int bottomLine) {
        this.topLine = topLine;
        this.bottomLine = bottomLine;
        this.raster = Exe.image.getRaster();
        checkForNote();
    }

    public void checkForNote() {
        if (checkBottomLineForNote()) {
            System.out.println("end");
        }

    }

    private boolean checkTopLineForNote() {
        return true;
    }

    private boolean checkBottomLineForNote() {
        for (int x = 0; x < Exe.image.getWidth(); x++) {
            if (raster.getSample(x, bottomLine + 1, 0) == 255) {
                pointer = pointer + "1";
            } else {
                pointer = pointer + "0";
            }
            if (pointer.contains(note)) {
                System.out.println("Note at Y:" + bottomLine + "\tX:" + x);
                pointer = "";
            }
        }

        return false;


    }

}
