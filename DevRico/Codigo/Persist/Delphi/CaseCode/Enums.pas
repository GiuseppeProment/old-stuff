unit Enums;

interface

type
  IDirecaoFetch = (primeiro,ultimo,proximo,previo,reavalia);
  IEstadoGenerico = (gInicial,gInicializado,gInativo,gAtivo,gFinalizando);
  IKnowType =
    (IsDouble,
    IsFloat,
    IsInt,
    IsShortInt,
    IsChar,
    IsCharArray,
    IsTimestamp,
    IsStringBlob,
    IsStringVar,
    IsStringFix,
    IsUnknow,
    // ponteiros
    IsDoublePointer,
    IsFloatPointer,
    IsIntPointer,
    IsShortIntPointer,
    IsCharPointer,
    IsCharArrayPointer,
    IsTimestampPointer,
    IsStringBlobPointer,
    IsStringVarPointer,
    IsStringFixPointer,
    IsUnknowPointer );

implementation

end.
