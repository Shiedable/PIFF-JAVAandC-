import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Write {
    public void write(File output, String[] arr) throws IOException {
        try {
            FileWriter writer = new FileWriter(output);

            for (int i = 0; i < arr.length; i++) {
                writer.write(arr[i]);
                writer.write("\n");
            }
            writer.close();
        }catch (IOException e){
            System.out.println("Writing err");
            e.printStackTrace();
        }
    }
}
