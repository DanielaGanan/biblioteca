#include "libro.h"

libro::libro(const QString &titulo, const QString &autor, const QString &genero, const QString &editorial, int año, const QString &isbn, int stock)
    : m_titulo(titulo), m_autor(autor), m_genero(genero), m_editorial(editorial), m_año(año), m_isbn(isbn), m_stock(stock)
{}

QString libro::getTitulo() const { return m_titulo; }
QString libro::getAutor() const { return m_autor; }
QString libro::getGenero() const { return m_genero; }
QString libro::getEditorial() const { return m_editorial; }
int libro::getAño() const { return m_año; }
QString libro::getIsbn() const { return m_isbn; }
int libro::getStock() const { return m_stock; }

// Métodos setters
void libro::setTitulo(const QString &titulo) { m_titulo = titulo; }
void libro::setAutor(const QString &autor) { m_autor = autor; }
void libro::setGenero(const QString &genero) { m_genero = genero; }
void libro::setEditorial(const QString &editorial) { m_editorial = editorial; }
void libro::setAño(int año) { m_año = año; }
void libro::setIsbn(const QString &isbn) { m_isbn = isbn; }
void libro::setStock(int stock) { m_stock = stock; }
