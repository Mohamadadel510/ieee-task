// Boxes problem
#include <stdio.h>
#include <stdlib.h>
#define MAX_HEIGHT 41

struct box
{
	int length;
    int width;
    int height;
};

typedef struct box box;

int get_volume(box b) {
    int val= b.height *b.length *b.width;
    return val;
}

int is_lower_than_max_height(box b) {
	if(b.height < 41)
    {
        return 1;
    }
    return 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	box *boxes = malloc(n * sizeof(box));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &boxes[i].length, &boxes[i].width, &boxes[i].height);
	}
	for (int i = 0; i < n; i++) {
		if (is_lower_than_max_height(boxes[i])) {
			printf("%d\n", get_volume(boxes[i]));
		}
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////
// small and large triangles
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
	
    float p[n];
    float area[n];
    for(int i = 0; i<n; i++){
        p[i] =(tr[i].a + tr[i].b + tr[i].c) / 2.0;
        area[i] = sqrtf(p[i]*(p[i]-tr[i].a)*(p[i]-tr[i].b)*(p[i]-tr[i].c));
    }
    for(int i = 0; i< n - 1; i++){
        for (int j =0; j < n-i-1; j++){
            if(area[j+1] < area[j]){
            float temparea = area[j];
            area[j] = area[j+1];
            area[j+1] = temparea;
             
             triangle temptr = tr[j];
             tr[j] = tr[j+1];
             tr[j+1] = temptr;
             
        }
        }
        
        
        
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////
// structring documents 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
struct document get_document(char* text) {
    struct document doc;
    doc.data = malloc(sizeof(struct paragraph)*MAX_PARAGRAPHS);
    doc.paragraph_count =0;
    
    char *para_str = strtok(text, "\n");
    while(para_str){
        struct paragraph* para = &doc.data[doc.paragraph_count];
         para->data = malloc(sizeof(struct sentence)*MAX_CHARACTERS);
         para->sentence_count =0;
         char *sen_str = strtok(para_str,".");
         
         while(sen_str){
            struct sentence *sen = &para->data[para->sentence_count];
            sen->data = malloc(sizeof(struct word)* MAX_CHARACTERS);
            sen->word_count = 0;
            char* word_str = strtok(sen_str, " ");
            while (word_str) {
                struct word* w = &sen->data[sen->word_count];
                w->data = malloc(strlen(word_str) + 1);
                strcpy(w->data, word_str);
                sen->word_count++;
                word_str = strtok(NULL, " ");
         } 
         para->sentence_count++;
            sen_str = strtok(NULL, ".");
         
    }
    doc.paragraph_count++;
        para_str = strtok(NULL, "\n");

    }
    return doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k -1];
}
//مش قادر احدد ليه هوه مش بيطبع الباراجرف بس بيطبع الباقي حاولت كتير بس معرفتش

void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}
//////////////////////////////
//post position
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 6

struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;



void print_all_packages(town t) {
    printf("%s:\n", t.name);
    for(int i =0; i< t.offices_count;i++)
    {
        printf("\t%d:\n", i);
        for(int j =0; j < t.offices[i].packages_count; j++)
        {
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
        
    } 
    
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
    post_office *src = &source->offices[source_office_index];
    post_office *trg = &target->offices[target_office_index];
    
    package *new_src = malloc(sizeof(package)*src->packages_count);
    package *new_trg = malloc(sizeof(package)*(src->packages_count+ trg->packages_count));
    
    int new_src_count =0;
    int new_trg_count = trg->packages_count;
    
    for(int i =0; i < trg->packages_count; i++)
    {
        new_trg[i] = trg->packages[i];
    }
    for(int i =0; i< src->packages_count;i++)
    {
        int w = src->packages[i].weight;
        if( w >= trg->min_weight && w <= trg->max_weight){
           new_trg[new_trg_count++] = src->packages[i];
        }
        else{
            new_src[new_src_count++] = src->packages[i];
        }
    }
    
    free(src->packages);
    free(trg->packages);
    src->packages = new_src;
    src->packages_count = new_src_count;

    trg->packages = new_trg;
    trg->packages_count = new_trg_count;
}

town town_with_most_packages(town* towns, int towns_count) {
    int max =-1;
    town *result =NULL;
    for(int i =0; i< towns_count; i++)
    {
        int count =0;
        for(int j =0;j<  towns[i].offices_count; j++)
        {
            count += towns[i].offices[j].packages_count;
        }
        if(count > max){
            max = count;
            result = &towns[i];
        }
        
    }
    return *result;
}

town* find_town(town* towns, int towns_count, char* name) {
    for(int i =0; i<towns_count; i++)
    {
        if(strcmp(towns[i].name, name)==0){
            return &towns[i];
        }
    }
    return NULL;
}

int main()
{
	int towns_count;
	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}
