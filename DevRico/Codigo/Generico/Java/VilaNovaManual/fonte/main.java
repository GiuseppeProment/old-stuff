//Source file: C:/DevRico/Codigo/Generico/Java/VilaNovaManual/fonte/main.java

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.border.*;
import com.sun.java.swing.JPanel;

class main 
{
   
   /**
   @roseuid 3C6718E602BE
   */
   public static main(String[] args) 
   {
		/*
		try {
	        	UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
	      	} catch (Exception exc) {
	          	System.err.println("Error loading L&F: " + exc);
	      	}
		*/
	      	try {
	        	UIManager.setLookAndFeel(UIManager.getCrossPlatformLookAndFeelClassName());
	      	} catch (Exception exc) {
	        	System.err.println("Error loading L&F: " + exc);
              	}

		JFrame f = new JFrame("Vila Nova");
	        f.addWindowListener(new WindowAdapter() {
	            public void windowClosing(WindowEvent e) {System.exit(0);}
	        });
	        //f.getContentPane().add("Center", demo);

		// montar o menu para teste
		// este ‚ a Barra de Menu
		JMenuBar menuBar = new JMenuBar();
		// este ‚ o item
		JMenu fileMenu = (JMenu) menuBar.add(new JMenu("Funcoes"));
		// estes subitens
		JMenuItem item = (JMenuItem) fileMenu.add(new JMenuItem("Saida"));
            	item.addActionListener(new ActionListener() {
                	public void actionPerformed(ActionEvent e) { System.exit(0); }
            		});
		item.setIcon( new ImageIcon("resources/save.gif"));
		//
		fileMenu.addSeparator();
		//
		JMenuItem sobre = (JMenuItem) fileMenu.add(new JMenuItem("Sobre"));
            	sobre.addActionListener(new ActionListener() {
                	public void actionPerformed(ActionEvent e) { showInfoDialog(); }
            		});
		sobre.setIcon( new ImageIcon("resources/new.gif"));
		// adiciona o menu
		f.getContentPane().add(menuBar, BorderLayout.NORTH);

		// adicionar o tabedpane
		JTabbedPane folheto = new JTabbedPane();
		// os JPanel seriam classes
		folheto.addTab("Folha #1", criaPainel1() );
		folheto.addTab("Folha #2",new JPanel());
		folheto.addTab("Folha #3",new JPanel());
		f.getContentPane().add( folheto , BorderLayout.CENTER);

	        f.pack();
	        Dimension d = Toolkit.getDefaultToolkit().getScreenSize();
	        //f.setLocation(d.width/2 , d.height/2 );
	        f.setSize( new Dimension(d.width/2,d.height/2) );
	        f.setVisible(true);
   }
   
   /**
   @roseuid 3C6718E602C0
   */
   public static void showInfoDialog() 
   {
		final String msg =
	            "When running the Java Sound demo as an applet these permissions\n" +
	            "are necessary in order to load/save files and record audio :  \n\n"+
	            "grant { \n" +
	            "  permission java.io.FilePermission \"<<ALL FILES>>\", \"read, write\";\n" +
	            "  permission javax.sound.sampled.AudioPermission \"record\"; \n" +
	            "  permission java.util.PropertyPermission \"user.dir\", \"read\";\n"+
	            "}; \n\n" +
	            "The permissions need to be added to the .java.policy file.";
	        new Thread(new Runnable() {
	            public void run() {
	                JOptionPane.showMessageDialog(null, msg, "Applet Info", JOptionPane.INFORMATION_MESSAGE);
	            }
	        }).start();
   }
   
   /**
   @roseuid 3C6718E602C7
   */
   public static JPanel criaPainel1() 
   {
		JPanel painel = new JPanel();
		painel.add( new JLabel("Esta ‚ a Um") );
		return painel;
   }
}
