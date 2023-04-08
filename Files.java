import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Files {
    public File iFile(String inputPath) {
        return new File(inputPath);
    }

    public File oFile(String outputPath) throws IOException {
        File outputFile = new File(outputPath);
        outputFile.createNewFile();
        return outputFile;
    }
}
