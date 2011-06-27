#ifndef _INNNER_DEFINE_H_
#define _INNNER_DEFINE_H_

////////////////////////////////////////////////////////////////////////////////////////////////////////

//##ModelId=4C64C1B70370
template <class T>
    class MapIterator
    {
    private:
	//##ModelId=4C64C1B70373
        typename T::iterator mCurrent;
	//##ModelId=4C64C1B70378
        typename T::iterator mEnd;
        /// Private constructor since only the parameterised constructor should be used
	//##ModelId=4C64C1B70380
        MapIterator() {};
    public:
        typedef typename T::referent_type MappedType;
        typedef typename T::key_type KeyType;

        /** Constructor.
        @remarks
            Provide a start and end iterator to initialise.
        */
	//##ModelId=4DE7374F025F
        MapIterator(typename T::iterator start, typename T::iterator end)
            : mCurrent(start), mEnd(end)
        {
        }

        /** Constructor.
        @remarks
            Provide a container to initialise.
        */
	//##ModelId=4C64C1B70381
        explicit MapIterator(T& c)
            : mCurrent(c.begin()), mEnd(c.end())
        {
        }

        /** Returns true if there are more items in the collection. */
	//##ModelId=4C64C1B70383
        bool hasMoreElements(void) const
        {
            return mCurrent != mEnd;
        }

        /** Returns the next value element in the collection, and advances to the next. */
	//##ModelId=4C64C1B70386
        typename T::referent_type getNext(void)
        {
            return (mCurrent++)->second;
        }
        /** Returns the next value element in the collection, without advancing to the next. */
	//##ModelId=4C64C1B70388
        typename T::referent_type peekNextValue(void)
        {
            return mCurrent->second;
        }
        /** Returns the next key element in the collection, without advancing to the next. */
	//##ModelId=4C64C1B7038A
        typename T::key_type peekNextKey(void)
        {
            return mCurrent->first;
        }
        /** Required to overcome intermittent bug */
	//##ModelId=4C64C1B7038C
 	    MapIterator<T> & operator=( MapIterator<T> &rhs )
 	    {
 		    mCurrent = rhs.mCurrent;
 		    mEnd = rhs.mEnd;
 		    return *this;
 	    }
        /** Returns a pointer to the next value element in the collection, without 
            advancing to the next afterwards. */
	//##ModelId=4C64C1B7038E
        typename T::referent_type* peekNextValuePtr(void)
        {
            return &(mCurrent->second);
        }
        /** Moves the iterator on one element. */
	//##ModelId=4C64C1B70390
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

//##ModelId=4C61002C0122
struct ContainerTreeInfoStrcT
{
	//##ModelId=4C61002C0152
	CDataElementManager *m_pElementManager;
	//##ModelId=4C64C447026E
	CTreeElementManager *m_pTreeElementManager;
	//##ModelId=4C653E100332
	CContainerRoot      *m_pContainerRoot;

	//##ModelId=4C61002C0157
	CImageList *m_pImageList;
	//##ModelId=4C61002C0164
	HTREEITEM	m_hRoot;
	//##ModelId=4C61002C01BE
	int         m_ItemImageNo[TREE_ITEM_IMAGE_NUM];
	
	//##ModelId=4C61002C01BF
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
