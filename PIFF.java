import java.io.File;
import java.io.IOException;

public class PIFF {
	static{
		System.loadLibrary("algstructs");
	}
	public native String[] algA();
	public native String[] algB(String choice);
	public native void passToC(String[] arr);

	public static void main(String[] args) throws IOException {

		Args A = new Args();
		A.argsHandling(args);

		Files IOF = new Files();
		File input = IOF.iFile(args[0]);
		File outputA = IOF.oFile(args[1]);
		File outputB = IOF.oFile(args[3]);

		Read reader = new Read();
		String[] arr = reader.read(input);

		PIFF objectPiff = new PIFF();
		objectPiff.passToC(arr);
		String[] arrA = objectPiff.algA();
		String[] arrB = objectPiff.algB(args[2]);

		Write writer = new Write();
		writer.write(outputA, arrA);
		writer.write(outputB, arrB);
	}
}