#ifndef _INNNER_DEFINE_H_
#define _INNNER_DEFINE_H_

////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
    class MapIterator
    {
    private:
        typename T::iterator mCurrent;
        typename T::iterator mEnd;
        /// Private constructor since only the parameterised constructor should be used
        MapIterator() {};
    public:
        typedef typename T::mapped_type MappedType;
        typedef typename T::key_type KeyType;

        /** Constructor.
        @remarks
            Provide a start and end iterator to initialise.
        */
        MapIterator(typename T::iterator start, typename T::iterator end)
            : mCurrent(start), mEnd(end)
        {
        }

        /** Constructor.
        @remarks
            Provide a container to initialise.
        */
        explicit MapIterator(T& c)
            : mCurrent(c.begin()), mEnd(c.end())
        {
        }

        /** Returns true if there are more items in the collection. */
        bool hasMoreElements(void) const
        {
            return mCurrent != mEnd;
        }

        /** Returns the next value element in the collection, and advances to the next. */
        typename T::mapped_type getNext(void)
        {
            return (mCurrent++)->second;
        }
        /** Returns the next value element in the collection, without advancing to the next. */
        typename T::mapped_type peekNextValue(void)
        {
            return mCurrent->second;
        }
        /** Returns the next key element in the collection, without advancing to the next. */
        typename T::key_type peekNextKey(void)
        {
            return mCurrent->first;
        }
        /** Required to overcome intermittent bug */
 	    MapIterator<T> & operator=( MapIterator<T> &rhs )
 	    {
 		    mCurrent = rhs.mCurrent;
 		    mEnd = rhs.mEnd;
 		    return *this;
 	    }
        /** Returns a pointer to the next value element in the collection, without 
            advancing to the next afterwards. */
        typename T::mapped_type* peekNextValuePtr(void)
        {
            return &(mCurrent->second);
        }
        /** Moves the iterator on one element. */
        void moveNext(void)
        {
            ++mCurrent;
        }
    };

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CDataElement;
class CDataContainer;
class CDataElementManager;
class CContainerRoot;
class CTreeElementManager;

#define TREE_ITEM_IMAGE_NUM 7

struct ContainerTreeInfoStrcT
{
	CDataElementManager *m_pElementManager;
	CTreeElementManager *m_pTreeElementManager;
	CContainerRoot      *m_pContainerRoot;

	CImageList *m_pImageList;
	HTREEITEM	m_hRoot;
	int         m_ItemImageNo[TREE_ITEM_IMAGE_NUM];
	
	ContainerTreeInfoStrcT()
	{
		m_pElementManager = NULL;
		m_pTreeElementManager = NULL;
		m_pContainerRoot = NULL;

		m_pImageList = NULL;
		m_hRoot = NULL;

		memset(m_ItemImageNo, 0, TREE_ITEM_IMAGE_NUM*sizeof(int));
	}
};







#endif