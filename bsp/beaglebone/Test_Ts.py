# coding: utf-8
import click

@click.command(help="")
@click.option("--output", "-o", required=True, type=click.Path(dir_okay=False, writable=True), help="output file path")
def cli(output):
    fo = open(output, "w")
    fo.write(
'''
    void Test() {}
'''
    )
    fo.close()

if __name__ == "__main__":
    cli()
