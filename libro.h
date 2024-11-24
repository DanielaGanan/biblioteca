#ifndef LIBRO_H
#define LIBRO_H
#include <QString>

class libro
{
public:
    // Constructor libro
    libro();
    libro(const QString &titulo, const QString &autor, const QString &genero, const QString &editorial, int año, const QString &isbn, int stock);

    // Métodos getters
    QString getTitulo() const;
    QString getAutor() const;
    QString getGenero() const;
    QString getEditorial() const;
    int getAño() const;
    QString getIsbn() const;
    int getStock() const;

    // Métodos setters
    void setTitulo(const QString &titulo);
    void setAutor(const QString &autor);
    void setGenero(const QString &genero);
    void setEditorial(const QString &editorial);
    void setAño(int año);
    void setIsbn(const QString &isbn);
    void setStock(int stock);

private:
    QString m_titulo;
    QString m_autor;
    QString m_genero;
    QString m_editorial;
    int m_año;
    QString m_isbn;
    int m_stock;
};

#endif // LIBRO_H
