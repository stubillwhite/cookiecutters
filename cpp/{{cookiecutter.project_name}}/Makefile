{% raw -%}
# vim:fdm=marker

# Constants                                                                 {{{1
# ==============================================================================

COLOR_BLUE=\033[0;34m
COLOR_NONE=\033[0m

{% endraw %}
EXECUTABLE=./build/{{cookiecutter.main_module_name}}/-sandbox
{% raw -%}

# Targets                                                                   {{{1
# ==============================================================================

# Help                              {{{2
# ======================================

help:
	@grep -E '^[0-9a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) \
		| sort \
		| awk 'BEGIN {FS = ":.*?## "}; {printf "$(COLOR_BLUE)%s|$(COLOR_NONE)%s\n", $$1, $$2}' \
		| column -t -s '|'

# Clean                             {{{2
# ======================================

.PHONY: clean
clean: ## Remove all artefacts
	@echo 'Cleaning application'
	@rm -rf \
		./build

.PHONY: clean-all
clean-all: clean ## Remove all artefacts and dependencies
	@echo 'Cleaning dependencies'

# Build                             {{{2
# ======================================

run: ## Build and run
	@echo 'Running application'
	@mkdir -p build 
	@cd build \
		&& cmake -DCMAKE_PROJECT_TOP_LEVEL_INCLUDES=cmake/conan_provider.cmake .. \
		&& cmake --build .
	@$(EXECUTABLE)

test:
	@cd build \
		&& ctest
{% endraw %}
