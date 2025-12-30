use {{cookiecutter.package_name}}::{{cookiecutter.package_name}}::add_five;

#[test]
fn add_five_then_returns_value_plus_five() {
    assert_eq!(add_five(23), 28);
}
