/*
   Copyright (c) 2012-1015 Alex Zhondin <qtinuum.team@gmail.com>

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef QTN_PROPERTY_H
#define QTN_PROPERTY_H

#include "PropertyBase.h"
#include "Auxiliary/PropertyDelegateInfo.h"
#include <functional>

class QtnPropertyDelegateInfoGetter;

class QTN_PE_CORE_EXPORT QtnProperty: public QtnPropertyBase
{
    Q_OBJECT
    Q_DISABLE_COPY(QtnProperty)

public:
    virtual ~QtnProperty();

    // delegates
    const QtnPropertyDelegateInfo* delegate() const;
    void setDelegate(const QtnPropertyDelegateInfo& delegate);
    void setDelegateCallback(const std::function<const QtnPropertyDelegateInfo*()>& callback);

    // casts
    QtnProperty* asProperty() override { return this; }
    const QtnProperty* asProperty() const override { return this; }

Q_SIGNALS:
    void propertyValueAccept(const QtnProperty* property, QtnPropertyValuePtr valueToAccept, bool* accept);

protected:
    explicit QtnProperty(QObject* parent);

private:
    QScopedPointer<QtnPropertyDelegateInfoGetter> m_delegateInfoGetter;
};

#endif // QTN_PROPERTY_H