#include "librodatos.h"

libroDatos::libroDatos()
{

    // Métodos getters
    QString libroDatos::getTitulo() const { return m_titulo; }
    QString libroDatos::getAutor() const { return m_autor; }
    QString libroDatos::getEditorial() const { return m_editorial; }
    int libroDatos::getAño() const { return m_año; }
    int libroDatos::getStock() const { return m_stock; }

    // Métodos setters
    void libroDatos::setTitulo(const QString &titulo) { m_titulo = titulo; }
    void libroDatos::setAutor(const QString &autor) { m_autor = autor; }
    void libroDatos::setEditorial(const QString &editorial) { m_editorial = editorial; }
    void libroDatos::setAño(int año) { m_año = año; }
    void libroDatos::setStock(int stock) { m_stock = stock; }


}




