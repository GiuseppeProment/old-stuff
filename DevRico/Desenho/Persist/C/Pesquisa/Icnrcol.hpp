#ifndef _ICNRCOL_
#define _ICNRCOL_
/*******************************************************************************
* FILE NAME: icnrcol.hpp                                                       *
*                                                                              *
* DESCRIPTION:                                                                 *
*   Declaration of the classes:                                                *
*     IContainerColumn                                                         *
*                                                                              *
* COPYRIGHT:                                                                   *
*   IBM Open Class Library                                                     *
*   (C) Copyright International Business Machines Corporation 1992, 1996       *
*   Licensed Material - Program-Property of IBM - All Rights Reserved.         *
*   US Government Users Restricted Rights - Use, duplication, or disclosure    *
*   restricted by GSA ADP Schedule Contract with IBM Corp.                     *
*                                                                              *
*******************************************************************************/

#include <ivbase.hpp>
#include <ihandle.hpp>

class IContainerWindow;
class IContainerControl;
class IContainerObject;
class IResourceId;
class IString;
class IDate;
class ITime;
class ICnrColumnData;
class ICnrControlData;
struct _FIELDINFO;

#pragma pack(4)

class IContainerColumn : public IVBase {
typedef IVBase
  Inherited;
public:
/*---------------------------------- Styles ----------------------------------*/
typedef unsigned long
  Style;

static const Style
  IC_IMPORTU string,
  IC_IMPORTU icon,
  IC_IMPORTU alignTop,
  IC_IMPORTU alignBottom,
  IC_IMPORTU alignVerticallyCentered,
  IC_IMPORTU alignLeft,
  IC_IMPORTU alignRight,
  IC_IMPORTU alignCentered;

/*------------------------------ Heading Style -------------------------------*/
typedef unsigned long
  HeadingStyle;

static const HeadingStyle
  IC_IMPORTU readOnlyHeading,
  IC_IMPORTU classDefaultHeadingStyle;

static Style
  defaultHeadingStyle    ( );

static void
  setDefaultHeadingStyle ( const HeadingStyle& headingStyle );

/*-------------------------------- Data Style --------------------------------*/
typedef unsigned long
  DataStyle;

static const DataStyle
  IC_IMPORTU date,
  IC_IMPORTU time,
  IC_IMPORTU number,
  IC_IMPORTU horizontalSeparator,
  IC_IMPORTU verticalSeparator,
  IC_IMPORTU handleDrawItem,
  IC_IMPORTU readOnly,
  IC_IMPORTU invisible,
  IC_IMPORTU classDefaultDataStyle;

static Style
  defaultDataStyle    ( );
static void
  setDefaultDataStyle ( const DataStyle& dataStyle );

/*------------------------------ Related Members -----------------------------*/
enum DataSource {
  isIcon,
  isIconViewText
  };

enum VerticalAlignment {
  top,
  bottom,
  centeredVertically
  };

enum HorizontalAlignment {
  left,
  right,
  centered
  };

/*------------------------------- Constructors -------------------------------*/
  IContainerColumn ( unsigned long       dataOffset,
                     const HeadingStyle& title = defaultHeadingStyle(),
                     const DataStyle&    data = defaultDataStyle() );

  IContainerColumn ( DataSource          objectDataType,
                     const HeadingStyle& title = defaultHeadingStyle(),
                     const DataStyle&    data = defaultDataStyle() );

  IContainerColumn ( const IContainerColumn& column);

virtual
 ~IContainerColumn ( );

/*----------------------------- Object Information ---------------------------*/
virtual IContainerColumn
 &setHeadingText       ( const char*           text ),
 &setHeadingText       ( const IResourceId&    textId );

virtual IContainerColumn
 &setHeadingIcon       ( const IPointerHandle& iconHandle ),
 &setHeadingIcon       ( const IResourceId&    iconId ),
 &setHeadingIcon       ( unsigned long         iconId );

virtual IString
  headingText          ( ) const;

virtual IPointerHandle
  headingIcon          ( ) const;

virtual IContainerColumn
 &enableHeadingUpdate  ( Boolean enable = true ),
 &disableHeadingUpdate ( ),
 &enableDataUpdate     ( Boolean enable = true ),
 &disableDataUpdate    ( );

virtual IContainerColumn
 &show                 ( Boolean visible = true ),
 &hide();

virtual IContainerColumn
 &showSeparators       ( const DataStyle& separatorStyles =
                           horizontalSeparator | verticalSeparator ),
 &hideSeparators       ( const DataStyle& separatorStyles =
                           horizontalSeparator | verticalSeparator );

virtual IContainerColumn
 &justifyData          ( VerticalAlignment   = centeredVertically,
                         HorizontalAlignment = centered ),
 &justifyHeading       ( VerticalAlignment   = centeredVertically,
                         HorizontalAlignment = centered );

virtual IContainerColumn
 &setDisplayWidth     ( unsigned long widthInPixels );

virtual unsigned long
  displayWidth        ( );

virtual IContainerColumn
 &setDataOffset       ( unsigned long dataOffset ),
 &setHelpId           ( unsigned long helpId );

unsigned long
  helpId              ( ) const;

Boolean
 isVisible              ( ) const,
 isDate                 ( ) const,
 isTime                 ( ) const,
 isNumber               ( ) const,
 isString               ( ) const,
 isIconHandle           ( ) const,
 isWriteable            ( ) const,
 isHeadingWriteable     ( ) const,
 isHeadingString        ( ) const,
 isHeadingIconHandle    ( ) const,
 hasHorizontalSeparator ( ) const,
 hasVerticalSeparator   ( ) const;


VerticalAlignment
  verticalDataAlignment      ( ) const,
  verticalHeadingAlignment   ( ) const;
HorizontalAlignment
  horizontalDataAlignment    ( ) const,
  horizontalHeadingAlignment ( ) const;

/*---------------------------Data Retrieval ----------------------------------*/
unsigned long
  dataAsNumber ( const IContainerObject* object ) const;
IString
  dataAsString ( const IContainerObject* object ) const;
IDate
  dataAsDate   ( const IContainerObject* object ) const;
ITime
  dataAsTime   ( const IContainerObject* object ) const;
IPointerHandle
  dataAsIcon   ( const IContainerObject* object ) const;

protected:
/*----------------------------- Object Attributes ----------------------------*/
virtual IContainerColumn
 &setTitleAttributes ( unsigned long  titleAttributes ),
 &setDataAttributes  ( unsigned long  dataAttributes );

virtual unsigned long
  titleAttributes    ( ) const,
  dataAttributes     ( ) const;

_FIELDINFO
 *columnInfo         ( ) const;

IContainerControl
 *container          ( ) const;

IContainerColumn
 &setContainer       ( IContainerControl* container ),
 &setColumnInfo      ( _FIELDINFO*        fieldinfo ),
 &invalidate         ( );

private:
/*--------------------------------- Private ----------------------------------*/
friend class IContainerControl;
friend class ICnrControlData;
friend class INativeContainerHandler;
friend class IColumnSet;
friend class IDetailsEditHandler;

const char*
  headingTextRef ( ) const;
_FIELDINFO
 *pfieldinfoCl;

IContainerControl
 *pcnrctlCl;
IPointerHandle
  ptrhCl;
static Style
  currentDefaultHeadingStyle,
  currentDefaultDataStyle;
unsigned long
  ulHelpId;
ICnrColumnData
 *columnData;

}; // IContainerColumn

#pragma pack()

  #include <icnrcol.inl>

#endif
