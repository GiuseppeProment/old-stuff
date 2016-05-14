import java.lang.*;

public class Teste {
	static {
		System.out.println("** iniciado...");
		System.loadLibrary("TESTE");
		//Runtime.getRuntime().loadLibrary("USER32");
		System.out.println("carregada...");
	}
	public int numero;
	public String Identificador;
	private static native void foo();
	//protected static native int GetClipboardData( int format);

	public static void main (String args[]) {
		System.out.println("chamando foo...");
		foo();
		//GetClipboardData( 1 );
		System.out.println("Termino normal.");
		}
}