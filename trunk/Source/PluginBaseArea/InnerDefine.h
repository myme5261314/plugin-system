#ifndef _INNNER_DEFINE_H_
#define _INNNER_DEFINE_H_

//////////////////////////�ڲ������ļ�///////////////////////////////////////

class CPluginDllManager;
class CFunctionPluginManager;
class CMessageListenerManager;
class CDataElementManager;

struct WorkspaceInfoStrcT
{
	CPluginDllManager		*m_pDllManager;
	CFunctionPluginManager	*m_pFunctionManager;
	CMessageListenerManager	*m_pMsgListenerManager;
	CDataElementManager     *m_pElementManager;

	WorkspaceInfoStrcT()
	{
		m_pDllManager         = NULL;
		m_pFunctionManager    = NULL;
		m_pMsgListenerManager = NULL;
		m_pElementManager     = NULL;
	}
};

////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////

//��ȡ��ǰ����·��.
bool GetCurrentModulePath(char *pFilePath);

//�ж��ļ��Ƿ����, ���ж��ļ��Ƿ�Ϊ��.
bool IsFileExisted(const char *pFilePathName, bool IsEmptyJudge=true);

//�������γɲ���б��ļ�.
bool FormPluginLstFile(const char *pFilePath);


#endif