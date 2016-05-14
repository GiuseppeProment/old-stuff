CREATE PROCEDURE INSERE 
	( nome VARCHAR(50), idade integer ) AS
BEGIN
	BEGIN
		INSERT INTO pessoa (nome, idade) VALUES (:nome, :idade);
	END
	EXIT;
END 
