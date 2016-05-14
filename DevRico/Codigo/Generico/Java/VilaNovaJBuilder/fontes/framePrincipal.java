
//Title:      Sistema Administrativo Simples
//Version:    
//Copyright:  Copyright (c) 1998
//Author:     Giuseppe
//Company:    Abstract 
//Description:primeiro sistema real feito em java e
//jBuilder
import java.awt.*;
import java.awt.event.*;
import borland.jbcl.control.*;
import borland.jbcl.layout.*;

public class framePrincipal extends DecoratedFrame
{

  //Construct the frame
  BorderLayout borderLayout1 = new BorderLayout();
  XYLayout xYLayout2 = new XYLayout();
  BevelPanel bevelPanel1 = new BevelPanel();
  MenuBar menuBar1 = new MenuBar();
  Menu menuFile = new Menu();
  MenuItem menuFileExit = new MenuItem();
  Menu menuHelp = new Menu();
  MenuItem menuHelpAbout = new MenuItem();
  StatusBar statusBar = new StatusBar();
  
  public framePrincipal()
  {
    try 
    {
      jbInit();
    }
    catch (Exception e)
    {
      e.printStackTrace();
    }
  }
//Component initialization
  
  private void jbInit() throws Exception 
  {
    this.setLayout(borderLayout1);
    this.setSize(new Dimension(400, 300));
    this.setTitle("Sistema Administrativo Vila Nova ");
    menuFile.setLabel("File");
    menuFileExit.setLabel("Exit");
    menuFileExit.addActionListener(new ActionListener() 
    {
      public void actionPerformed(ActionEvent e)
      {
        fileExit_actionPerformed(e);
      }
    });
    menuHelp.setLabel("Help");
    menuHelpAbout.setLabel("About");
    menuHelpAbout.addActionListener(new ActionListener() 
    {
      public void actionPerformed(ActionEvent e)
      {
        helpAbout_actionPerformed(e);
      }
    });
    bevelPanel1.setLayout(xYLayout2);
    menuFile.add(menuFileExit);
    menuHelp.add(menuHelpAbout);
    menuBar1.add(menuFile);
    menuBar1.add(menuHelp);
    this.setMenuBar(menuBar1);
    this.add(statusBar, BorderLayout.SOUTH);
    this.add(bevelPanel1, BorderLayout.CENTER);
  }
//File | Exit action performed
  
  public void fileExit_actionPerformed(ActionEvent e)
  {
    System.exit(0);
  }
//Help | About action performed
  
  public void helpAbout_actionPerformed(ActionEvent e)
  {
    framePrincipal_AboutBox dlg = new framePrincipal_AboutBox(this);
    Dimension dlgSize = dlg.getPreferredSize();
    Dimension frmSize = getSize();
    Point loc = getLocation();
    dlg.setLocation((frmSize.width - dlgSize.width) / 2 + loc.x, (frmSize.height - dlgSize.height) / 2 + loc.y);
    dlg.setModal(true);
    dlg.show();
  }
}
 