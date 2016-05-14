FUNCTION NFILTER(bFilter)
  Local nCount := 0
  If bFilter # NIL
	  Count to nCount for Eval(bFilter) .and. ! Deleted()
  Else
	  Count to nCount for ! Deleted()
  Endif
  RETURN(nCount)

// **
