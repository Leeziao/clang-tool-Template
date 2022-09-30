#include <llvm/Support/raw_ostream.h>
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>

#include <clang/AST/ASTContext.h>
#include <clang/ASTMatchers/ASTMatchers.h>
#include <clang/ASTMatchers/ASTMatchFinder.h>

#include <testlib/testlib.h>

using namespace llvm;
using namespace clang::ast_matchers;
using namespace clang::tooling;

static cl::OptionCategory MyToolCategory("My tool options");
static cl::extrahelp CommonHelp(CommonOptionsParser::HelpMessage);
static cl::extrahelp MoreHelp("\nMore help text...\n");

int main(int argc, const char **argv) {
    auto optionsParser = CommonOptionsParser::create(argc, argv, MyToolCategory);

    ClangTool tool(optionsParser->getCompilations(),
                   optionsParser->getSourcePathList());

	showMsg();

    return 0;
}
