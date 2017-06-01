#ifndef _SPTHREADFUNC_H__
#define _SPTHREADFUNC_H__

class sPthreadFunc{
	public:
		virtual bool sPthread_Init();
		virtual bool sPthread_End();
		virtual bool sPthread_Run();
		virtual bool sPthread_isFinal();
};
#endif
