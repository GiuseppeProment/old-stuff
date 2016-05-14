; EAGLE Autorouter Control File

[Default]

  RoutingGrid     = 50mil

  ; Minimum Distances:

  mdWireWire      = 18mil
  mdWirePad       = 18mil
  mdWireDimension = 40mil
  mdWireVia       = 18mil
  mdWireRestrict  = 18mil

  mdViaPad        = 18mil
  mdViaDimension  = 40mil
  mdViaVia        = 18mil
  mdViaRestrict   = 18mil

  ; Trace Parameters:

  tpWireWidth     = 40mil
  tpViaDiameter   = 40mil
  tpViaDrill      = 24mil
  tpViaShape      = Round

  ; Preferred Directions:

  PrefDir.1       = 0
  PrefDir.2       = 0
  PrefDir.3       = 0
  PrefDir.4       = 0
  PrefDir.5       = 0
  PrefDir.6       = 0
  PrefDir.7       = 0
  PrefDir.8       = 0
  PrefDir.9       = 0
  PrefDir.10      = 0
  PrefDir.11      = 0
  PrefDir.12      = 0
  PrefDir.13      = 0
  PrefDir.14      = 0
  PrefDir.15      = 0
  PrefDir.16      = *

  ; Cost Factors:

  cfVia           =    8
  cfNonPref       =    5
  cfChangeDir     =    2
  cfOrthStep      =    2
  cfDiagStep      =    3
  cfExtdStep      =    0
  cfBonusStep     =    1
  cfMalusStep     =    1
  cfPadImpact     =    4
  cfSmdImpact     =    4
  cfBusImpact     =    0
  cfHugging       =    3
  cfAvoid         =    4

  cfBase.1        =    0
  cfBase.2        =    1
  cfBase.3        =    1
  cfBase.4        =    1
  cfBase.5        =    1
  cfBase.6        =    1
  cfBase.7        =    1
  cfBase.8        =    1
  cfBase.9        =    1
  cfBase.10       =    1
  cfBase.11       =    1
  cfBase.12       =    1
  cfBase.13       =    1
  cfBase.14       =    1
  cfBase.15       =    1
  cfBase.16       =    0

  ; Maximum Number of...:

  mnVias          =    0
  mnSegments      = 9999
  mnExtdSteps     = 9999
  mnRipupLevel    =   10
  mnRipupSteps    =  100
  mnRipupTotal    =  100

[Busses]

  @Route

  cfNonPref       =    4
  cfBusImpact     =    4
  cfHugging       =    0

[Route]

  @Default


[Optimize1]

  @Route

  cfVia           =   99
  cfExtdStep      =   30
  cfHugging       =    1
  mnVias          =   20
  mnExtdSteps     =    1
  mnRipupLevel    =    0

[Optimize2]

  @Optimize1

  cfHugging       =    0

[Optimize3]

  @Optimize2

  cfChangeDir     =    6

