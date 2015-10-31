#ifndef SHADERITEM_H
#define SHADERITEM_H

#include <QObject>
#include "ShaderParameterModel.h"

class ShaderItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(QString fragmentShader READ fragmentShader NOTIFY fragmentShaderChanged)
    Q_PROPERTY(QString vertexShader READ vertexShader NOTIFY vertexShaderChanged)
    Q_PROPERTY(QVariant parameters READ parameters NOTIFY parametersChanged)

public:
    explicit ShaderItem(QObject *parent = 0);

    QString name() const;
    QString fragmentShader() const;
    QString vertexShader() const;
    QVariant parameters() const;

    void setName(const QString &n);
    void setFragmentShader(const QString &f);
    void setVertexShader(const QString &v);
    void addParameters(ShaderParameterModel * const p);

signals:
    void nameChanged();
    void fragmentShaderChanged();
    void vertexShaderChanged();
    void parametersChanged();

private:
    QString _name;
    QString _fragmentShader;
    QString _vertexShader;
    ShaderParameterModel * _parameters;
};

Q_DECLARE_METATYPE(ShaderItem *)

#endif // SHADERITEM_H
