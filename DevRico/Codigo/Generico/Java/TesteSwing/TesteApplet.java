
//package PackTeste;

import java.applet.*;
import java.awt.*;
/**
 * This applet was generated by a SmartGuide.
 * 
 */
public class TesteApplet extends Applet implements java.awt.event.ActionListener {
	private Button ivjButton1 = null;
	private Checkbox ivjCheckbox1 = null;
	private Frame ivjFrame1 = null;
	private MenuBar ivjFrame1MenuBar = null;
	private Menu ivjMenu1 = null;
	private Menu ivjMenu2 = null;
	private MenuItem ivjMenuItem1 = null;
	private MenuItem ivjMenuItem2 = null;
	public int Campo;

/**
 * Method to handle events for the ActionListener interface.
 * @param e java.awt.event.ActionEvent
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
public void actionPerformed(java.awt.event.ActionEvent e) {
	// user code begin {1}
	// user code end
	if ((e.getSource() == getButton1()) ) {
		conn0(e);
	}
	// user code begin {2}
	// user code end
}

/**
 * conn0:  (Button1.action.actionPerformed(java.awt.event.ActionEvent) --> Frame1.show())
 * @param arg1 java.awt.event.ActionEvent
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
private void conn0(java.awt.event.ActionEvent arg1) {
	try {
		// user code begin {1}
		// user code end
		getFrame1().show();
		// user code begin {2}
		// user code end
	} catch (java.lang.Throwable ivjExc) {
		// user code begin {3}
		// user code end
		handleException(ivjExc);
	}
}

/**
 * Gets the applet information.
 * @return java.lang.String
 */
public String getAppletInfo() {
	return "PackTeste.TesteApplet created using VisualAge for Java.";
}

/**
 * Return the Button1 property value.
 * @return java.awt.Button
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
private Button getButton1() {
	if (ivjButton1 == null) {
		try {
			ivjButton1 = new java.awt.Button();
			ivjButton1.setName("Button1");
			ivjButton1.setBounds(24, 19, 125, 30);
			ivjButton1.setLabel("Abrir Janela");
			// user code begin {1}
			// user code end
		} catch (java.lang.Throwable ivjExc) {
			// user code begin {2}
			// user code end
			handleException(ivjExc);
		}
	};
	return ivjButton1;
}

/**
 * Return the Checkbox1 property value.
 * @return java.awt.Checkbox
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
private Checkbox getCheckbox1() {
	if (ivjCheckbox1 == null) {
		try {
			ivjCheckbox1 = new java.awt.Checkbox();
			ivjCheckbox1.setName("Checkbox1");
			ivjCheckbox1.setBounds(23, 28, 125, 30);
			ivjCheckbox1.setLabel("Checkbox1");
			// user code begin {1}
			// user code end
		} catch (java.lang.Throwable ivjExc) {
			// user code begin {2}
			// user code end
			handleException(ivjExc);
		}
	};
	return ivjCheckbox1;
}

/**
 * Return the Frame1 property value.
 * @return java.awt.Frame
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
private Frame getFrame1() {
	if (ivjFrame1 == null) {
		try {
			ivjFrame1 = new java.awt.Frame();
			ivjFrame1.setName("Frame1");
			ivjFrame1.setMenuBar(getFrame1MenuBar());
			ivjFrame1.setLayout(null);
			ivjFrame1.setBounds(229, 30, 374, 203);
			ivjFrame1.setTitle("Janela Teste");
			ivjFrame1.add(getCheckbox1(), getCheckbox1().getName());
			// user code begin {1}
			// user code end
		} catch (java.lang.Throwable ivjExc) {
			// user code begin {2}
			// user code end
			handleException(ivjExc);
		}
	};
	return ivjFrame1;
}

/**
 * Return the Frame1MenuBar property value.
 * @return java.awt.MenuBar
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
private MenuBar getFrame1MenuBar() {
	if (ivjFrame1MenuBar == null) {
		try {
			ivjFrame1MenuBar = new java.awt.MenuBar();
			ivjFrame1MenuBar.add(getMenu1());
			ivjFrame1MenuBar.add(getMenu2());
			// user code begin {1}
			// user code end
		} catch (java.lang.Throwable ivjExc) {
			// user code begin {2}
			// user code end
			handleException(ivjExc);
		}
	};
	return ivjFrame1MenuBar;
}

/**
 * Return the Menu1 property value.
 * @return java.awt.Menu
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
private Menu getMenu1() {
	if (ivjMenu1 == null) {
		try {
			ivjMenu1 = new java.awt.Menu();
			ivjMenu1.setLabel("Menu1");
			ivjMenu1.add(getMenuItem1());
			// user code begin {1}
			// user code end
		} catch (java.lang.Throwable ivjExc) {
			// user code begin {2}
			// user code end
			handleException(ivjExc);
		}
	};
	return ivjMenu1;
}

/**
 * Return the Menu2 property value.
 * @return java.awt.Menu
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
private Menu getMenu2() {
	if (ivjMenu2 == null) {
		try {
			ivjMenu2 = new java.awt.Menu();
			ivjMenu2.setLabel("Menu2");
			ivjMenu2.add(getMenuItem2());
			// user code begin {1}
			// user code end
		} catch (java.lang.Throwable ivjExc) {
			// user code begin {2}
			// user code end
			handleException(ivjExc);
		}
	};
	return ivjMenu2;
}

/**
 * Return the MenuItem1 property value.
 * @return java.awt.MenuItem
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
private MenuItem getMenuItem1() {
	if (ivjMenuItem1 == null) {
		try {
			ivjMenuItem1 = new java.awt.MenuItem();
			ivjMenuItem1.setLabel("MenuItem1");
			// user code begin {1}
			// user code end
		} catch (java.lang.Throwable ivjExc) {
			// user code begin {2}
			// user code end
			handleException(ivjExc);
		}
	};
	return ivjMenuItem1;
}

/**
 * Return the MenuItem2 property value.
 * @return java.awt.MenuItem
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
private MenuItem getMenuItem2() {
	if (ivjMenuItem2 == null) {
		try {
			ivjMenuItem2 = new java.awt.MenuItem();
			ivjMenuItem2.setLabel("MenuItem2");
			// user code begin {1}
			// user code end
		} catch (java.lang.Throwable ivjExc) {
			// user code begin {2}
			// user code end
			handleException(ivjExc);
		}
	};
	return ivjMenuItem2;
}

/**
 * Called whenever the part throws an exception.
 * @param exception java.lang.Throwable
 */
private void handleException(Throwable exception) {

	/* Uncomment the following lines to print uncaught exceptions to stdout */
	// System.out.println("--------- UNCAUGHT EXCEPTION ---------");
	// exception.printStackTrace(System.out);
}

/**
 * Handle the Applet init method.
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
public void init() {
	super.init();
	try {
		setName("TesteApplet");
		setLayout(null);
		setSize(192, 247);
		add(getButton1(), getButton1().getName());
		initConnections();
		// user code begin {1}
		// user code end
	} catch (java.lang.Throwable ivjExc) {
		// user code begin {2}
		// user code end
		handleException(ivjExc);
	}
}

/**
 * Initializes connections
 */
/* WARNING: THIS METHOD WILL BE REGENERATED. */
private void initConnections() {
	// user code begin {1}
	// user code end
	getButton1().addActionListener(this);
}

/**
 * main entrypoint - starts the part when it is run as an application
 * @param args java.lang.String[]
 */
public static void main(java.lang.String[] args) {
	try {
		java.awt.Frame frame;
		try {
			Class aFrameClass = Class.forName("uvm.abt.edit.TestFrame");
			frame = (java.awt.Frame)aFrameClass.newInstance();
		} catch (java.lang.Throwable ivjExc) {
			frame = new java.awt.Frame();
		}
		PackTeste.TesteApplet aTesteApplet = new PackTeste.TesteApplet();
		frame.add("Center", aTesteApplet);
		frame.setSize(aTesteApplet.getSize());
		aTesteApplet.init();
		aTesteApplet.start();
		frame.setVisible(true);

		aTesteApplet.destroy();
	} catch (Throwable exception) {
		System.err.println("Exception occurred in main() of java.applet.Applet");
	}
}

}