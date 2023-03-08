#include "ModelPart.h"
#include <vtkSTLReader.h>
#include <vtkSmartPointer.h>
#include <vtkDataSetMapper.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>

ModelPart::ModelPart(const QList<QVariant>& data, ModelPart* parent )
    : m_itemData(data), m_parentItem(parent) {

    /* You probably want to give the item a default colour */
}

ModelPart::~ModelPart() {
    qDeleteAll(m_childItems);
}

void ModelPart::appendChild( ModelPart* item ) {
    /* Add another model part as a child of this part
     * (it will appear as a sub-branch in the treeview)
     */
    item->m_parentItem = this;
    m_childItems.append(item);
}

ModelPart* ModelPart::child( int row ) {
    /* Return pointer to child item in row below this item.
     */
    if (row < 0 || row >= m_childItems.size())
        return nullptr;
    return m_childItems.at(row);
}

int ModelPart::childCount() const {
    /* Count number of child items
     */
    return m_childItems.count();
}

int ModelPart::columnCount() const {
    /* Count number of columns (properties) that this item has.
     */
    return m_itemData.count();
}

QVariant ModelPart::data(int column) const {
    /* Return the data associated with a column of this item 
     *  Note on the QVariant type - it is a generic placeholder type
     *  that can take on the type of most Qt classes. It allows each 
     *  column or property to store data of an arbitrary type.
     */
    if (column < 0 || column >= m_itemData.size())
        return QVariant();
    return m_itemData.at(column);
}

void ModelPart::set(int column, const QVariant &value) {
    /* Set the data associated with a column of this item 
     */
    if (column < 0 || column >= m_itemData.size())
        return;

    m_itemData.replace(column, value);
}

ModelPart* ModelPart::parentItem() {
    return m_parentItem;
}

int ModelPart::row() const {
    /* Return the row index of this item, relative to it's parent.
     */
    if (m_parentItem)
        return m_parentItem->m_childItems.indexOf(const_cast<ModelPart*>(this));
    return 0;
}

void ModelPart::setColour(const unsigned char R, const unsigned char G, const unsigned char B) {
    /* This is a placeholder function that will be used in the next worksheet */
    
    /* As the name suggests ... */
}

unsigned char ModelPart::getColourR() {
    /* This is a placeholder function that will be used in the next worksheet */
    
    /* As the name suggests ... */
    return 0;   // needs updating
}

unsigned char ModelPart::getColourG() {
    /* This is a placeholder function that will be used in the next worksheet */
    
    /* As the name suggests ... */
    return 0;   // needs updating
}

unsigned char ModelPart::getColourB() {
    /* This is a placeholder function that will be used in the next worksheet */
    
    /* As the name suggests ... */
    return 0;   // needs updating
}

void ModelPart::setVisible(bool isVisible) {
    /* This is a placeholder function that will be used in the next worksheet */
    
    /* As the name suggests ... */
}

bool ModelPart::visible() {
    /* This is a placeholder function that will be used in the next worksheet */
    
    /* As the name suggests ... */
    return false;
}

void ModelPart::loadSTL( QString fileName ) {

    vtkSmartPointer<vtkSTLReader> reader = vtkSmartPointer<vtkSTLReader>::New();

    reader->SetFileName(fileName.toStdString().c_str());
    reader->Update();
    file = reader;

    vtkNew<vtkPolyDataMapper> pMapper;
    pMapper->SetInputConnection(reader->GetOutputPort());

    vtkNew<vtkActor> pActor;
    pActor->SetMapper(pMapper);
    actor = pActor;
    
}

vtkSmartPointer<vtkActor> ModelPart::getActor() {

    return actor;

}

vtkActor* ModelPart::getNewActor() {
     
    vtkNew<vtkPolyDataMapper> pointMapper;
    pointMapper->SetInputConnection(file->GetOutputPort());
     
    vtkNew<vtkActor> pointActor;
    pointActor->SetMapper(pointMapper);
     
    return pointActor;
    
}

