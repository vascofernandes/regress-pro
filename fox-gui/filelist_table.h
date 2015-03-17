#ifndef FILELIST_TABLE_H
#define FILELIST_TABLE_H

#include <fx.h>

class filelist_table : public FXTable {
protected:
    filelist_table() {};
private:
    filelist_table(const filelist_table&);
    filelist_table &operator=(const filelist_table&);

public:
    filelist_table(FXComposite *p,FXObject* tgt=NULL,FXSelector sel=0,FXuint opts=0,FXint x=0,FXint y=0,FXint w=0,FXint h=0,FXint pl=DEFAULT_MARGIN,FXint pr=DEFAULT_MARGIN,FXint pt=DEFAULT_MARGIN,FXint pb=DEFAULT_MARGIN);

    void append_filenames(FXString *filenames);
    int samples_number() { return entries_no; }

protected:
    int entries_no;
};

#endif
