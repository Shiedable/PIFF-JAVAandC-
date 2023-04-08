
public class Args {
    public void argsHandling(String[] args){
      if (args.length == 4)
      {
        if (!args[2].equalsIgnoreCase("z") && !args[2].equalsIgnoreCase("y") && !args[2].equalsIgnoreCase("x"))
            throw new RuntimeException("not a valid coordinate");
      }else {
          throw new RuntimeException("args count not 4");
      }}
}
